#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#include "visitorcodegenerator.hpp"
#include "visitortypechecker.hpp"
#include "visitormemmap.hpp"

#include "../parser/astnode.hpp"
#include "../parser/astarrayaccessnode.hpp"
#include "../parser/astarraynode.hpp"
#include "../parser/astassignnode.hpp"
#include "../parser/astcallnode.hpp"
#include "../parser/astcaselabelsnode.hpp"
#include "../parser/astcasenode.hpp"
#include "../parser/astclausenode.hpp"
#include "../parser/astcompoundstmtnode.hpp"
#include "../parser/astconstantnode.hpp"
#include "../parser/astdeclnode.hpp"
#include "../parser/astexpressionnode.hpp"
#include "../parser/astifnode.hpp"
#include "../parser/astparamnode.hpp"
#include "../parser/astprocnode.hpp"
#include "../parser/astprognode.hpp"
#include "../parser/astreadnode.hpp"
#include "../parser/astreturnnode.hpp"
#include "../parser/aststmtnode.hpp"
#include "../parser/astsymnode.hpp"
#include "../parser/asttypenode.hpp"
#include "../parser/astvariablenode.hpp"
#include "../parser/astwhilenode.hpp"
#include "../parser/astwritenode.hpp"

/**************************
 * Code generator visitor *
 **************************/

CodeGeneratorVisitor::CodeGeneratorVisitor(
    std::ostream& output, 
    std::ostream& log,
    TypeCheckVisitor& typeCheckVisitor,
    MemoryMapVisitor& memoryMapVisitor
)
: mLogS {log}
, mOutputS {output}
, mTypeCheckVisitor {typeCheckVisitor}
, mMemoryMapVisitor {memoryMapVisitor}
, mCurrentProcedure {""}
{
}

void CodeGeneratorVisitor::initialize() {
    mOutputS <<
        "#-------------------------------#\n"
        "# nolife compiler               #\n"
        "# Josh Chandler                 #\n"
        "#-------------------------------#\n"
    ;

    mOutputS <<
        "   .intel_syntax\n"
        "   .section .rodata\n"
        ".io_format:\n"
        "   .string \"%d\\12\"\n"
        "   .string \"%f\\12\"\n"
        "   .string \"%c\\12\"\n"
        "   .string \"%s\\12\"\n"
        ".io_format_in:\n"
        "   .string \"%d\"\n"
        "   .string \"%f\"\n"
        "   .string \"%c\"\n"
        "_constant:\n"
    ;
    
    auto &constMap = mMemoryMapVisitor.mConstantMap;

    // turn map into a list of pairs
    using pairType = std::pair<std::string, MemoryInfo>;
    std::vector<pairType> pairList;
    for (auto mapPair : constMap) {
        pairList.push_back(pairType(mapPair.first, mapPair.second));
    }

    // sort by offset
    std::sort(pairList.begin(), pairList.end(), 
        [](const pairType &a, const pairType &b) -> bool {
            return a.second.offset < b.second.offset;
        }
    );

    // output constants
    for (auto constantPair : pairList) {
        std::string image = constantPair.first;
        MemoryInfo info = constantPair.second;

        if (info.type == ast::Type::Types::Float) {
            mOutputS << "   .float " << image << std::endl;
        } else if (info.type == ast::Type::Types::Character
                || info.type == ast::Type::Types::StringConstant
        ) {
            // change single quotes to double quotes
            std::replace(image.begin(), image.end(), '\'', '\"');
            mOutputS << "   .string " << image << std::endl;
        }
    }
    
    // might change this?
    mOutputS <<
        ".text\n"
        "   .globl main;\n"
        "   .type main, @function\n"
    ;
}

void CodeGeneratorVisitor::finalize() {
    
}

void CodeGeneratorVisitor::visitUniversal(ast::Base *b) {
    // mLogS << "(universal)\n";

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void CodeGeneratorVisitor::visit(ast::Base* b) {
    visitUniversal(b);
}

void CodeGeneratorVisitor::visit(ast::Program* p) {
    // make sure we have a type map and a memory map
    if (!mTypeCheckVisitor.mDone) {
        mLogS << "Detected missing symbol table. Creating now.\n";
        p->accept(mTypeCheckVisitor);
    }

    if (!mMemoryMapVisitor.mDone) {
        mLogS << "Detected missing memory map. Creating now.\n";
        p->accept(mMemoryMapVisitor);
        mMemoryMapVisitor.dumpOutput(mLogS);
    }

    initialize(); // output default header info

    mCurrentProcedure = p->getSymbol()->getImage();

    mOutputS <<
        "main:\n"
        "   push %ebp\n"
        "   mov %ebp, %esp\n"
    ;
    
    visitUniversal(p);

    mOutputS <<
        "#  Return 0\n"
        "   mov %eax, 0\n"
        "   leave\n"
        "   ret\n"
    ;

    finalize();
}

void CodeGeneratorVisitor::visit(ast::Declaration* d) {
    mLogS << "Visiting a decl node. Current procedure is " << mCurrentProcedure << std::endl;
    auto children = d->getChildren();
    auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];

    int farOffset = 0;

    for (auto node : children) {
        if (auto typeNode = dynamic_cast<ast::Type*>(node)) {
            ast::Symbol* symbolNode;
            
            // obtain correct symbol
            if (symbolNode = typeNode->childAsSymbol()) {
            } else if (symbolNode = typeNode->childAsArray()->childAsSymbol()) {
            } 
            
            // update biggest offset
            if (symbolNode) {
                auto info = memMap[symbolNode->getImage()];
                if (!info.isArray) {
                    // variable
                    if (info.offset < farOffset) {
                        farOffset = info.offset;
                    }
                } else {
                    // array
                    if (info.lowerOffset < farOffset) {
                        farOffset = info.lowerOffset;
                    }
                }

            } else {
                mLogS << "Detected a procedure in a decl node.\n";
            }
        }
    }

    mOutputS <<
        "   sub %esp, " + std::to_string(std::abs(farOffset)) + "\n"
    ;

    visitUniversal(d);
}

void CodeGeneratorVisitor::visit(ast::CompoundStatement* cs) {
    visitUniversal(cs);
}

void CodeGeneratorVisitor::visit(ast::Parameters* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Symbol* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Type* t) {
    visitUniversal(t);
}

void CodeGeneratorVisitor::visit(ast::Integer* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Float* f) {
    visitUniversal(f);
}

void CodeGeneratorVisitor::visit(ast::Character* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Void* v) {
    visitUniversal(v);
}

void CodeGeneratorVisitor::visit(ast::ArrayAccess* aa) {
    visitUniversal(aa);

    auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];
    auto info = memMap[aa->getSymbol()->getImage()];

    std::string tempReg = mRegisterManager.get_free_register();

    // check if bounds is a character or a number
    int unitOffset = 0;
    try {
        // the bound is an integer
        unitOffset = std::stoi(info.lowBoundString);
    } catch (std::invalid_argument) {
        // the bound is a character
        unitOffset = (unsigned int)info.lowBoundString[1];
    }

    mOutputS <<
        "#  Array access: " + aa->getSymbol()->getImage() + "[" + aa->getExpression()->getCalculationLocation() + "]" + "\n"
        "   mov %eax, " + aa->getExpression()->getCalculationLocation() + "\n"
        "   sub %eax, " + std::to_string(unitOffset) + "\n"
        "   mov %edx, 4\n"
        "   imul %edx\n"
        "   mov %edx, %ebp\n"
        "   sub %edx, " + std::to_string(std::abs(info.lowerOffset)) + "\n"
        "   add %edx, %eax\n"
        "   mov " + tempReg + ", %edx\n"
    ;

    aa->setCalculationLocation("[ " + tempReg + " ]");
}

void CodeGeneratorVisitor::visit(ast::Array* a) {
    visitUniversal(a);
}

void CodeGeneratorVisitor::visit(ast::Assignment* a) {
    visitUniversal(a); // derive locations

    std::string tempReg = mRegisterManager.get_free_register();

    // one of these will fail
    auto varNode = dynamic_cast<ast::Variable*>(a->getChildren()[0]);
    auto arrNode = dynamic_cast<ast::ArrayAccess*>(a->getChildren()[0]);

    auto expNode = dynamic_cast<ast::Expression*>(a->getChildren()[1]);

    std::string varLoc = "";

    if (arrNode) {
        varLoc = arrNode->getCalculationLocation();
    } else if (varNode) {
        varLoc = varNode->getCalculationLocation();
    }

    mOutputS <<
        "#  Assignment: " + varNode->getSymbol()->getImage() + " := " + expNode->getCalculationLocation() + "\n"
        "   mov " + tempReg + ", " + expNode->getCalculationLocation() + "\n"
        "   mov " + varLoc + ", " + tempReg + "\n"
    ;

    mOutputS <<
        "#  Cleared the register manager.\n"
    ;
    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Call* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void CodeGeneratorVisitor::visit(ast::Case* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Clause* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Constant* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Expression* e) {
    visitUniversal(e);

    std::string tempReg;
    auto labels = ConditionalLabelManager::LabelTriple("", "", "");

    if (e->getChildren().size() == 1) {
        // single child expression
        if (auto constantNode = dynamic_cast<ast::Constant*>(e->getChildren()[0])) {
            // child is a constant
            // set location to constant location

            std::string constImage = constantNode->getImage();
            auto type = constantNode->getType();

            if (type == ast::Type::Types::Integer) {
                e->setCalculationLocation(constImage);
            } else if (type == ast::Type::Types::Character) {
                std::ostringstream ss;
                ss << "0x" << std::hex << (unsigned int)constImage[1];
                e->setCalculationLocation(ss.str());
            } else { // float (string constants are handled elseware)
                int offset = mMemoryMapVisitor.mConstantMap[constImage].offset;
                std::string location = "[ offset flat:_constant + " + std::to_string(offset) + " ]";
                e->setCalculationLocation(location);
            }
        } else if (auto arrayAccessNode = dynamic_cast<ast::ArrayAccess*>(e->getChildren()[0])) { 
            e->setCalculationLocation(arrayAccessNode->getCalculationLocation());
        } else if (auto varNode = dynamic_cast<ast::Variable*>(e->getChildren()[0])) {
            e->setCalculationLocation(varNode->getCalculationLocation());
        } else if (auto expNode = dynamic_cast<ast::Expression*>(e->getChildren()[0])) {
            if (e->getOperation() == ast::Expression::Not) {
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # NOT " + expNode->getCalculationLocation() + "\n"
                    "   mov %eax, " + expNode->getCalculationLocation() + "\n"
                    "   cmp %eax, 0\n"
                    "   je " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            }
        }
    } else {
        // binary expression
        auto leftExp = dynamic_cast<ast::Expression*>(e->getChildren()[0]);
        auto rightExp = dynamic_cast<ast::Expression*>(e->getChildren()[1]);

        using EX = ast::Expression;
        switch (e->getOperation()) {
            case EX::Plus:
                // plus
                tempReg = mRegisterManager.get_free_register();

                `

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " + " + rightExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                    "   add " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                ;

                mRegisterManager.clear_single(leftExp->getCalculationLocation());

                e->setCalculationLocation(tempReg);
            break;
            case EX::Minus:
                // minus
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " - " + rightExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                    "   add " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                ;

                mRegisterManager.clear_single(leftExp->getCalculationLocation());

                e->setCalculationLocation(tempReg);
            break;
            case EX::Multiply:
                // multiply
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " * " + rightExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                    "   imul " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::Modulo:
                // modulo
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " % " + rightExp->getCalculationLocation() + "\n"
                    "   xor %edx, %edx\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                    "   idiv " + tempReg + "\n"
                    "   mov " + tempReg + ", %edx\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::LessThanOrEqual:
                // <=
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " <= " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   jle " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::LessThan:
                // <
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " < " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   jl " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::GreaterThanOrEqual:
                // >=
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " >= " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   jge " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::GreaterThan:
                // >
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " > " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   jg " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::Equals:
                // =
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " = " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   je " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::NotEqual:
                // <>
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " <> " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   cmp %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   jne " + labels.labelTrue + "\n"
                    "" + labels.labelFalse + ":\n"
                    "   mov " + tempReg + ", 0\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelTrue + ":\n"
                    "   mov " + tempReg + ", 0xffffffff\n"
                    "   jmp " + labels.labelEnd + "\n"
                    "" + labels.labelEnd + ":\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::And:
                // AND
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " AND " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   and %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", %eax\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
            case EX::Or:
                // OR
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "   # " + leftExp->getCalculationLocation() + " OR " + rightExp->getCalculationLocation() + "\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   or %eax, " + rightExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", %eax\n"
                ;

                e->setCalculationLocation(tempReg);
            break;
        }
    }
}

void CodeGeneratorVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Procedure* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Return* r) {
    visitUniversal(r);
}

void CodeGeneratorVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
    auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];
    v->setCalculationLocation("dword ptr [ %ebp" + std::to_string(memMap[v->getSymbol()->getImage()].offset) + " ]");
}

void CodeGeneratorVisitor::visit(ast::While* w) {
    visitUniversal(w);
}

void CodeGeneratorVisitor::visit(ast::Write* w) {
    visitUniversal(w); // calculate offsets

    if (auto constant = dynamic_cast<ast::Constant*>(w->getChildren()[0])) {
        // child is a string constant

        std::string image = constant->getImage();
        int offset = mMemoryMapVisitor.mConstantMap[image].offset;
        std::string constantLocation = "[ offset flat:_constant + " + std::to_string(offset) + " ]";
        std::string formatLocation = "offset flat:.io_format";

        if (constant->getType() == ast::Type::Types::StringConstant) {
            formatLocation = "[ offset flat:.io_format + 12 ]";
        }

        mOutputS << "#  Printing string constant: " + image + "\n";

        mOutputS <<
            "   push " + constantLocation + "\n"
            "   push " + formatLocation + "\n"
            "   call printf\n"
            "   add %esp, 8\n"
        ;
        
    } else if (auto expression = dynamic_cast<ast::Expression*>(w->getChildren()[0])) {
        // child is an expression

        mOutputS << "#  Printing expression:\n";

        std::string formatLocation = "offset flat:.io_format";

        if (expression->getType() == ast::Type::Types::Character) {
            formatLocation = "[ offset flat:.io_format + 8 ]";
        } 
        
        if (expression->getType() == ast::Type::Types::Float) {
            formatLocation = "[ offset flat:.io_format + 4 ]";
            std::string tempLocation = mRegisterManager.get_free_register();

            // convert float to double with floating point stack
            mOutputS <<
                "#  Printing float constant\n"
                // "   mov " + tempLocation + ", " + expression->getCalculationLocation() + "\n"
                "   sub %esp, 4\n" // allocate space for double
                "   push " + expression->getCalculationLocation() + "\n"
                "   fld dword ptr [ %esp ]\n"
                "   fstp qword ptr [ %esp ]\n"
                "   push " + formatLocation + "\n"
                "   call printf\n"
                "   add %esp, 12\n" // printf args
            ;

            // clear used register
            mRegisterManager.clear_all();
        } else {
            // output on anything but a float
            mOutputS <<
                "   push " + expression->getCalculationLocation() + "\n"
                "   push " + formatLocation + "\n"
                "   call printf\n"
                "   add %esp, 8\n"
            ;
        }
    }

    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Read* r) {
    visitUniversal(r);

    if (auto arrNode = dynamic_cast<ast::ArrayAccess*>(r->getChildren()[0])) {
        std::string image = arrNode->getSymbol()->getImage();
        std::string location = arrNode->getCalculationLocation();
        auto type = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure][image].type;

        mOutputS <<
            "#  READ ( " + location + " ) ( ArrayAccess )\n"
            "   lea %eax, " + location + "\n"
            "   push %eax\n"
        ;

        // push correct format string
        if (type == ast::Type::Types::Integer) {
            mOutputS << "   push [ offset flat:.io_format_in + 0 ]\n";
        } else if (type == ast::Type::Types::Float) {
            mOutputS << "   push [ offset flat:.io_format_in + 3 ]\n";
        } else if (type == ast::Type::Types::Character) {
            mOutputS << "   push [ offset flat:.io_format_in + 6 ]\n";
        }
        
        mOutputS <<
            "   call scanf\n"
            "   add %esp, 8\n"
        ;
    } else if (auto varNode = dynamic_cast<ast::Variable*>(r->getChildren()[0])) {
        std::string image = varNode->getSymbol()->getImage();
        std::string location = varNode->getCalculationLocation();
        auto type = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure][image].type;
        int offset = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure][image].offset;

        mOutputS <<
            "#  READ ( " + location + " )\n"
            "   mov %eax, %ebp\n"
            "   sub %eax, " + std::to_string(std::abs(offset)) + "\n"
            "   push %eax\n"
        ;

        // push correct format string
        if (type == ast::Type::Types::Integer) {
            mOutputS << "   push [ offset flat:.io_format_in + 0 ]\n";
        } else if (type == ast::Type::Types::Float) {
            mOutputS << "   push [ offset flat:.io_format_in + 3 ]\n";
        } else if (type == ast::Type::Types::Character) {
            mOutputS << "   push [ offset flat:.io_format_in + 6 ]\n";
        }
        
        mOutputS <<
            "   call scanf\n"
            "   add %esp, 8\n"
        ;
    }

    mRegisterManager.clear_all();
}
