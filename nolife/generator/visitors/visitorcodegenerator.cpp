#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <algorithm>
#include <regex>

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
    
    mOutputS <<
        ".text\n"
        "   .globl main\n"
        "   .type main, @function\n"
    ;
}

void CodeGeneratorVisitor::finalize() {
    
}

void CodeGeneratorVisitor::visitUniversal(ast::Base *b) {
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

    mCurrentProcedure = "main";

    mOutputS <<
        "main:\n"
        "   push %ebp\n"
        "   mov %ebp, %esp\n"
    ;
    
    p->getChildren()[0]->accept(*this); // symbol
    if (p->getChildren()[1] != nullptr) {
        p->getChildren()[1]->accept(*this); // decls
    }
    if (p->getChildren()[2] != nullptr) {
        p->getChildren()[2]->accept(*this); // compound statement
    }

    mOutputS <<
        "#  Return 0\n"
        "   mov %eax, 0\n"
        "   leave\n"
        "   ret\n"
    ;

    // generate code for procedures in procedure queue
    while (!mProcQueue.empty()) {
        mOutputS << "# ---------------------------------------------------------------------------- #\n";
        mLogS << "Processing procedure " << mProcQueue.front()->getSymbol()->getImage() << "\n";
        mProcQueue.front()->accept(*this);
        mProcQueue.pop();
    }

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
                //
            } else if (typeNode->childAsArray() != nullptr) {
                symbolNode = typeNode->childAsArray()->childAsSymbol();
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

            typeNode->accept(*this);

            } else {
                // procedure, add to processing queue
                auto procNode = typeNode->childAsProcedure();
                mLogS << "added procedure " << procNode->getSymbol()->getImage() << " to procedure queue.\n";
                mProcQueue.push(procNode);
            }
        }
    }

    mOutputS <<
        "#  Allocating stack for " + mCurrentProcedure + "\n"
        "   sub %esp, " + std::to_string(std::abs(farOffset)) + "\n"
    ;
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

    if (memMap.count(aa->getSymbol()->getImage())) {
        // local array, do nothing
    } else {
        // main array, change memmap to main
        memMap = mMemoryMapVisitor.mProcedureToSymbolsMap["main"];
    }
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

    if (info.offset >= 0) {
        // accessing an array in parameters
        mOutputS <<
            "#  Array access: " + aa->getSymbol()->getImage() + "[" + aa->getExpression()->getCalculationLocation() + "] (PARAM)" + "\n"
            "   mov %eax, " + aa->getExpression()->getCalculationLocation() + "\n"
            "   sub %eax, " + std::to_string(unitOffset) + "\n"
            "   mov %edx, 4\n"
            "   imul %edx\n" // offset from base is in eax
            "#  Derive beginning of array from parameter\n"
            "   mov %edx, [ %ebp+" + std::to_string(info.offset + 12) + " ]\n"
            "   add %edx, %eax\n"
            "   mov " + tempReg + ", %edx\n"
        ;
    } else if (mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure].count(aa->getSymbol()->getImage())) {
        // accessing a local array
        mOutputS <<
            "#  Array access: " + aa->getSymbol()->getImage() + "[" + aa->getExpression()->getCalculationLocation() + "] (LOCAL)" + "\n"
            "   mov %eax, " + aa->getExpression()->getCalculationLocation() + "\n"
            "   sub %eax, " + std::to_string(unitOffset) + "\n"
            "   mov %edx, 4\n"
            "   imul %edx\n"
            "   mov %edx, %ebp\n"
            "   sub %edx, " + std::to_string(std::abs(info.lowerOffset)) + "\n"
            "   add %edx, %eax\n"
            "   mov " + tempReg + ", %edx\n"
        ;
    } else {
        // accessing a global array
        mOutputS <<
            "#  Array access: " + aa->getSymbol()->getImage() + "[" + aa->getExpression()->getCalculationLocation() + "] (GLOBAL)" + "\n"
            "   mov %eax, " + aa->getExpression()->getCalculationLocation() + "\n"
            "   sub %eax, " + std::to_string(unitOffset) + "\n"
            "   mov %edx, 4\n"
            "   imul %edx\n" // offset from base is in eax
            "#  Load access link and get variable from main\n"
            "   mov %edx, [ %ebp + 8 ]\n"
            "   add %edx, " + std::to_string(mMemoryMapVisitor.mProcedureToSymbolsMap["main"][aa->getSymbol()->getImage()].lowerOffset) + "\n"
            "#  Add offset\n"
            "   add %edx, %eax\n"
            "   mov " + tempReg + ", %edx\n"
        ;
    }

    mRegisterManager.clear_single(aa->getCalculationLocation());
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
    std::string funcName = c->getSymbol()->getImage();
    int extraStack = 0;
    int nextTempOffset = 4;
    auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];

    // push registers
    mOutputS << "#  Saving registers\n";
    mLogS << "Saving regs\n";
    auto free_regs = mRegisterManager.get_all_free_registers();
    auto freecheck = [this](std::string reg) { return mRegisterManager.get_eligibility(reg); };
    free_regs.erase(std::remove_if(free_regs.begin(), free_regs.end(), freecheck), free_regs.end());
    for (auto reg : free_regs) {
        mOutputS << "   push " + reg + "\n";
    }

    // forwards
    for (auto it = c->getChildren().begin(); it != c->getChildren().end(); it++) {
        // skip the symbol node
        if (dynamic_cast<ast::Symbol*>(*it)) {
            continue;
        }

        // first pass:
        // put any expression/const results on the stack

        auto paramExpNode = dynamic_cast<ast::Expression*>(*it);
        if (!paramExpNode->childAsVariable()) {
            paramExpNode->accept(*this);
            // expression or constant. store result on stack and store address
            mOutputS <<
                "#  Storing expression result on stack\n"
                "   push " + paramExpNode->getCalculationLocation() + "\n"
            ;
            mRegisterManager.clear_single(paramExpNode->getCalculationLocation());
            paramExpNode->setTempOffset(nextTempOffset);
            nextTempOffset += 4;
            extraStack += 4;
        }
    }

    // store this esp in edx
    mOutputS <<
        "#  Store temporary %esp (which will be the base of the temporary parameter stack) in register\n"
        "   lea %edx, [ %esp+" + std::to_string(extraStack) + " ]\n"
    ;

    // backwards
    for (auto it = c->getChildren().rbegin(); it != c->getChildren().rend(); it++) {
        // skip the symbol node
        if (dynamic_cast<ast::Symbol*>(*it)) {
            continue;
        }

        // second pass:
        // put actual variable addresses on the stack

        // evaluate and push parameters
        auto paramExpNode = dynamic_cast<ast::Expression*>(*it);
        if (paramExpNode->childAsVariable()) {
            paramExpNode->accept(*this);

            mOutputS <<
                "#  Pushing procedure argument (Variable)\n"
                "   lea %eax, " + deriveAddress(paramExpNode->getCalculationLocation()) + "\n"
                "   push %eax\n"
            ;
            mRegisterManager.clear_single(paramExpNode->getCalculationLocation());   
        } else {
            // expression
            mOutputS <<
                "#  Pushing temporary stack address\n"
                "   mov %eax, %edx\n"
                "   sub %eax, " + std::to_string(paramExpNode->getTempOffset()) + "\n"
                "   push %eax\n"
            ;
        }
    }

    // push access link
    if (mCurrentProcedure == "main") {
        mOutputS <<
            "#  Push main's access link\n"
            "   push %ebp\n"
        ;
    } else {
        mOutputS <<
            "#  Push main's access link (already on the stack)\n"
            "   push [ %ebp+8 ]\n"
        ;
    }

    // call
    mOutputS <<
        "   call " + funcName + "\n"
        "   add %esp, " + std::to_string(extraStack + 4 + (c->getChildren().size() - 1) * 4) + "\n"
    ;

    // recover registers
    mOutputS << "#  Recovering registers\n";
    mLogS << "Recovering regs\n";
    for (auto it = free_regs.rbegin(); it != free_regs.rend(); it++) {
        mOutputS << "   push " + *it + "\n";
    }
}

void CodeGeneratorVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void CodeGeneratorVisitor::visit(ast::Case* c) {
    // generate code for the expression
    mOutputS << "#  Generating expression code for case statement\n";
    auto expNode = dynamic_cast<ast::Expression*>(c->getChildren()[0]);
    expNode->accept(*this);

    mOutputS << "#  Comparing with each label\n";
    mCaseLabelManager.newCase();

    for (int i = 1; i < c->getChildren().size(); i++) {
        // for each clause node, store start/end labels and generate cmps and jumps
        auto clauseNode = dynamic_cast<ast::Clause*>(c->getChildren()[i]);
        auto labelNode = clauseNode->getLabelNode();

        clauseNode->setAsmStartLabel(mCaseLabelManager.generateLabel());
        clauseNode->setAsmEndLabel(mCaseLabelManager.getEnd());

        for (auto labelNodeChild : labelNode->getChildren()) {
            // for each constant, compare and jmp
            auto constNode = dynamic_cast<ast::Constant*>(labelNodeChild);
            auto psuedoExp = ast::Expression(constNode);
            psuedoExp.setType(constNode->getType());
            psuedoExp.setCalculationLocation(constNode->getImage());
            std::string result = printCompare(ast::Expression::Equals, expNode, &psuedoExp);

            mOutputS <<
                "#  Case when " + expNode->getCalculationLocation() + " == " + psuedoExp.getCalculationLocation() + "\n"
                "   cmp " + result + ", 0xffffffff\n"
                "   je " + clauseNode->getAsmStartLabel() + "\n"
            ;

            mRegisterManager.clear_single(result);
        }
    }

    mOutputS << 
        "#  Jump to end of case on no matches\n"
        "   jmp " + mCaseLabelManager.getEnd() + "\n"
    ;

    for (int i = 1; i < c->getChildren().size(); i++) {
        // visit the clauses and generate their code
        c->getChildren()[i]->accept(*this);
    }

    // mark end of case
    mOutputS <<
        "" + mCaseLabelManager.getEnd() + ":\n"
    ;

    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Clause* c) {
    mOutputS <<
        "" + c->getAsmStartLabel() + ":\n";
        "#  Compound statement in a clause\n"
    ;

    // generate code
    c->getChildren()[1]->accept(*this);

    // jump to end
    mOutputS <<
        "   jmp " + c->getAsmEndLabel() + "\n"
    ;
}

void CodeGeneratorVisitor::visit(ast::Constant* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Expression* e) {
    visitUniversal(e);

    constexpr ast::Type::Types FLOAT = ast::Type::Types::Float;
    constexpr ast::Type::Types INT   = ast::Type::Types::Integer;
    constexpr ast::Type::Types CHAR  = ast::Type::Types::Character;

    std::string tempReg;
    auto labels = ConditionalLabelManager::LabelTriple("", "", "");
    auto myRealType = e->getType();
    auto myConvertedType = e->getConvertedType();

    if (e->getChildren().size() == 1) {
        // single child expression
        if (auto constantNode = dynamic_cast<ast::Constant*>(e->getChildren()[0])) {
            // child is a constant
            // set location to constant location

            std::string constImage = constantNode->getImage();
            auto type = constantNode->getType();

            if (type == ast::Type::Types::Integer) {
                e->setCalculationLocation(constImage);

                if (myConvertedType == FLOAT) {
                    e->setCalculationLocation( printConversion(INT, FLOAT, constImage) );
                }
            } else if (type == ast::Type::Types::Character) {
                std::ostringstream ss;
                ss << "0x" << std::hex << (unsigned int)constImage[1];
                e->setCalculationLocation(ss.str());
            } else { // float (string constants are handled elseware)
                int offset = mMemoryMapVisitor.mConstantMap[constImage].offset;
                std::string location = "[ _constant + " + std::to_string(offset) + " ]";
                e->setCalculationLocation(location);

                if (myConvertedType == INT) {
                    e->setCalculationLocation( printConversion(FLOAT, INT, location) );
                }
            }
        } else if (auto arrayAccessNode = dynamic_cast<ast::ArrayAccess*>(e->getChildren()[0])) { 
            e->setCalculationLocation(arrayAccessNode->getCalculationLocation());
        } else if (auto varNode = dynamic_cast<ast::Variable*>(e->getChildren()[0])) {
            e->setCalculationLocation(varNode->getCalculationLocation());
            // check if there needs to be a conversion done
            if (myRealType != myConvertedType) {
                if (myConvertedType == INT) {
                    e->setCalculationLocation( printConversion(FLOAT, INT, varNode->getCalculationLocation()) );
                } else if (myConvertedType == FLOAT) {
                    e->setCalculationLocation( printConversion(INT, FLOAT, varNode->getCalculationLocation()) );
                }
            }
        } else if (auto callNode = dynamic_cast<ast::Call*>(e->getChildren()[0])) {
            tempReg = mRegisterManager.get_free_register();
            mOutputS <<
                "#  Grab return value\n"
                "   mov " + tempReg + ", %eax\n"
            ;
            e->setCalculationLocation(tempReg);
        } else if (auto expNode = dynamic_cast<ast::Expression*>(e->getChildren()[0])) {
            if (e->getOperation() == ast::Expression::Not) {
                tempReg = mRegisterManager.get_free_register();
                labels = mConditionalLabelManager.generateLabelTriple();

                mOutputS <<
                    "#  NOT " + expNode->getCalculationLocation() + "\n"
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

                mRegisterManager.clear_single(expNode->getCalculationLocation());
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

                // myRealType = Children's converted type
                if (myRealType == ast::Type::Types::Integer) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " + " + rightExp->getCalculationLocation() + " (INT)\n"
                        "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                        "   add " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                    ;
                } else if (myRealType == ast::Type::Types::Float) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " + " + rightExp->getCalculationLocation() + " (FLOAT)\n"
                        "   push " + leftExp->getCalculationLocation() + "\n"
                        "   fld dword ptr [ %esp ]\n"
                        "   push " + rightExp->getCalculationLocation() + "\n"
                        "   fadd dword ptr [ %esp ]\n"
                        "   add %esp, 4\n"
                        "   fstp dword ptr [ %esp ] \n"
                        "   pop " + tempReg + "\n"
                    ;

                }

                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
                e->setCalculationLocation(tempReg);
            break;
            case EX::Minus:
                // minus
                tempReg = mRegisterManager.get_free_register();

                if (myRealType == INT) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " - " + rightExp->getCalculationLocation() + "\n"
                        "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                        "   sub " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                    ;
                    mRegisterManager.clear_single(leftExp->getCalculationLocation());
                } else if (myRealType == FLOAT) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " - " + rightExp->getCalculationLocation() + " (FLOAT)\n"
                        "   push " + leftExp->getCalculationLocation() + "\n"
                        "   fld dword ptr [ %esp ]\n"
                        "   push " + rightExp->getCalculationLocation() + "\n"
                        "   fsub dword ptr [ %esp ]\n"
                        "   add %esp, 4\n"
                        "   fstp dword ptr [ %esp ] \n"
                        "   pop " + tempReg + "\n"
                    ;
                }

                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
                e->setCalculationLocation(tempReg);
            break;
            case EX::Multiply:
                // multiply
                tempReg = mRegisterManager.get_free_register();

                if (myRealType == INT) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " * " + rightExp->getCalculationLocation() + "\n"
                        "   mov " + tempReg + ", " + leftExp->getCalculationLocation() + "\n"
                        "   imul " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                    ;
                } else if (myRealType == FLOAT) {
                    mOutputS <<
                        "#  " + leftExp->getCalculationLocation() + " * " + rightExp->getCalculationLocation() + " (FLOAT)\n"
                        "   push " + leftExp->getCalculationLocation() + "\n"
                        "   fld dword ptr [ %esp ]\n"
                        "   push " + rightExp->getCalculationLocation() + "\n"
                        "   fmul dword ptr [ %esp ]\n"
                        "   add %esp, 4\n"
                        "   fstp dword ptr [ %esp ] \n"
                        "   pop " + tempReg + "\n"
                    ;
                }

                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
                e->setCalculationLocation(tempReg);
            break;
            case EX::Modulo:
                // modulo
                // only is acceptable on ints
                tempReg = mRegisterManager.get_free_register();

                mOutputS <<
                    "#  " + leftExp->getCalculationLocation() + " % " + rightExp->getCalculationLocation() + "\n"
                    "   xor %edx, %edx\n"
                    "   mov %eax, " + leftExp->getCalculationLocation() + "\n"
                    "   mov " + tempReg + ", " + rightExp->getCalculationLocation() + "\n"
                    "   idiv " + tempReg + "\n"
                    "   mov " + tempReg + ", %edx\n"
                ;

                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
                e->setCalculationLocation(tempReg);
            break;
            case EX::LessThanOrEqual:
                // <=
                tempReg = printCompare(ast::Expression::Operation::LessThanOrEqual, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
            case EX::LessThan:
                // <
                tempReg = printCompare(ast::Expression::Operation::LessThan, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
            case EX::GreaterThanOrEqual:
                // >=
                tempReg = printCompare(ast::Expression::Operation::GreaterThanOrEqual, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
            case EX::GreaterThan:
                // >
                tempReg = printCompare(ast::Expression::Operation::GreaterThan, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
            case EX::Equals:
                // =
                tempReg = printCompare(ast::Expression::Operation::Equals, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
            case EX::NotEqual:
                // <>
                tempReg = printCompare(ast::Expression::Operation::NotEqual, leftExp, rightExp);
                e->setCalculationLocation(tempReg);
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
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
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
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
                mRegisterManager.clear_single(leftExp->getCalculationLocation());
                mRegisterManager.clear_single(rightExp->getCalculationLocation());
            break;
        }

        // check if there needs to be a conversion done
        if (myRealType != myConvertedType) {
            if (myConvertedType == INT) {
                e->setCalculationLocation( printConversion(FLOAT, INT, tempReg) );
            } else if (myConvertedType == FLOAT) {
                e->setCalculationLocation( printConversion(INT, FLOAT, tempReg) );
            }
        }
    } // binary expression else
}

void CodeGeneratorVisitor::visit(ast::If* i) {
    // visit expression to get memory location
    i->getChildren()[0]->accept(*this);

    auto expNode = dynamic_cast<ast::Expression*>(i->getChildren()[0]);
    auto labels = mConditionalLabelManager.generateLabelTriple();
    std::string tempLocation = expNode->getCalculationLocation();

    if (expNode->getChildren().size() == 1) {
        // single child expression
        auto type = ast::Type::Types::Integer;
        auto tempConstNode = ast::Constant("0", type);
        auto tempExpNode = ast::Expression(&tempConstNode);
        tempExpNode.setCalculationLocation("0");
        tempExpNode.setType(type);
        tempLocation = printCompare(ast::Expression::Operation::NotEqual, expNode, &tempExpNode);
    }

    mOutputS <<
        "#  If " + expNode->getCalculationLocation() + "\n"
        "   cmp " + tempLocation + ", 0\n"
        "   je " + labels.labelFalse + "\n"
        "" + labels.labelTrue + ":\n"
    ;
    mRegisterManager.clear_single(expNode->getCalculationLocation());

    // generate code for true
    i->getChildren()[1]->accept(*this);

    mOutputS <<
        "   jmp " + labels.labelEnd + "\n"
        "" + labels.labelFalse + ":\n"
    ;
    if (i->getChildren()[2] != nullptr) {
        // there's an else
        // generate code for false
        i->getChildren()[2]->accept(*this);
    }

    mOutputS <<
        "" + labels.labelEnd + ":\n"
    ;

    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Procedure* p) {
    mCurrentProcedure = p->getSymbol()->getImage();

    mOutputS <<
        "" + mCurrentProcedure + ":\n"
        "   push %ebp\n"
        "   mov %ebp, %esp\n"
    ;
    
    p->getChildren()[0]->accept(*this); // symbol
    if (p->getChildren()[1] != nullptr) {
        p->getChildren()[1]->accept(*this); // decls
    }
    if (p->getChildren()[3] != nullptr) {
        p->getChildren()[3]->accept(*this); // params
    }
    if (p->getChildren()[2] != nullptr) {
        p->getChildren()[2]->accept(*this); // compound statement
    }

    mOutputS <<
        "#  default leave return\n"
        "   leave\n"
        "   ret\n"
    ;
}

void CodeGeneratorVisitor::visit(ast::Return* r) {
    visitUniversal(r); // visit expression to derive location

    auto expNode = dynamic_cast<ast::Expression*>(r->getChildren()[0]);

    mOutputS <<
        "#  Return " + expNode->getCalculationLocation() + "\n"
        "   mov %eax, " + expNode->getCalculationLocation() + "\n"
        "   leave\n"
        "   ret\n"
    ;

    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
    auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];

    if (memMap.count(v->getSymbol()->getImage())) {
        // var is in current procedure
        int offset;
        if (memMap[v->getSymbol()->getImage()].isArray) {
            // array
            offset = memMap[v->getSymbol()->getImage()].lowerOffset;
        } else {
            // not an array
            offset = memMap[v->getSymbol()->getImage()].offset;
        }
    
        if (offset < 0) {
            v->setCalculationLocation("dword ptr [ %ebp" + std::to_string(offset) + " ]");
        } else {
            // greater or equal to zero. paramter in stack
            // parameter is an address. dereference it.
            auto tempReg = mRegisterManager.get_free_register();

            mOutputS <<
                "#  Deference paremeter address\n"
                "   mov " + tempReg + ", dword ptr [ %ebp+" + std::to_string(12 + offset) + " ]\n"
            ;
            
            v->setCalculationLocation("[ " + tempReg + " ]");
        }
    } else {
        // var is in main
        memMap = mMemoryMapVisitor.mProcedureToSymbolsMap["main"];
        int offset = memMap[v->getSymbol()->getImage()].offset;
        auto tempReg = mRegisterManager.get_free_register();

        mOutputS <<
            "#  Load access link and get variable from main\n"
            "   mov %eax, [ %ebp + 8 ]\n"
            "   add %eax, " + std::to_string(offset) + "\n"
            "   mov " + tempReg + ", [ %eax ]\n"
        ;

        v->setCalculationLocation(tempReg);
    }
}

void CodeGeneratorVisitor::visit(ast::While* w) {
    auto labels = mConditionalLabelManager.generateLabelTriple();

    mOutputS <<
        "#  While loop\n"
        "" + labels.labelTrue + ":\n"
    ;

    std::string tempLocation;
    // evaluate expression
    auto condExpNode = dynamic_cast<ast::Expression*>(w->getChildren()[0]);
    condExpNode->accept(*this);
    tempLocation = condExpNode->getCalculationLocation();

    if (condExpNode->getChildren().size() == 1) {
        // single child expression
        auto type = ast::Type::Types::Integer;
        auto tempConstNode = ast::Constant("0", type);
        auto tempExpNode = ast::Expression(&tempConstNode);
        tempExpNode.setCalculationLocation("0");
        tempExpNode.setType(type);
        tempLocation = printCompare(ast::Expression::Operation::NotEqual, condExpNode, &tempExpNode);
    }

    mOutputS <<
        "   cmp " + tempLocation + ", 0\n"
        "   je " + labels.labelEnd + "\n"
    ;
    mRegisterManager.clear_single(tempLocation);

    auto stmtNode = dynamic_cast<ast::Statement*>(w->getChildren()[1]);
    stmtNode->accept(*this);

    mOutputS <<
        "   jmp " + labels.labelTrue + "\n"
        "" + labels.labelEnd + ":\n"
    ;

    mRegisterManager.clear_all();
}

void CodeGeneratorVisitor::visit(ast::Write* w) {
    visitUniversal(w); // calculate offsets

    if (auto constant = dynamic_cast<ast::Constant*>(w->getChildren()[0])) {
        // child is a string constant

        std::string image = constant->getImage();
        int offset = mMemoryMapVisitor.mConstantMap[image].offset;
        std::string constantLocation = "[ offset _constant + " + std::to_string(offset) + " ]";
        std::string formatLocation = "offset .io_format";

        if (constant->getType() == ast::Type::Types::StringConstant) {
            formatLocation = "[ offset .io_format + 12 ]";
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

        std::string formatLocation = "offset .io_format";

        if (expression->getType() == ast::Type::Types::Character) {
            formatLocation = "[ offset .io_format + 8 ]";
        } 
        
        if (expression->getType() == ast::Type::Types::Float) {
            formatLocation = "[ offset .io_format + 4 ]";
            // std::string tempLocation = mRegisterManager.get_free_register();

            // convert float to double with floating point stack
            mOutputS <<
                "#  Printing expression: (FLOAT)\n"
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
                "#  Printing expression: (NON-FLOAT)\n"
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
        if (type == ast::Type::Types::Undefined) {
            type = mMemoryMapVisitor.mProcedureToSymbolsMap["main"][image].type;
        }

        mOutputS <<
            "#  READ ( " + location + " ) ( ArrayAccess )\n"
            "   lea %eax, " + location + "\n"
            "   push %eax\n"
        ;

        // push correct format string
        if (type == ast::Type::Types::Integer) {
            mOutputS << "   push [ offset .io_format_in + 0 ]\n";
        } else if (type == ast::Type::Types::Float) {
            mOutputS << "   push [ offset .io_format_in + 3 ]\n";
        } else if (type == ast::Type::Types::Character) {
            mOutputS << "   push [ offset .io_format_in + 6 ]\n";
        }
        
        mOutputS <<
            "   call scanf\n"
            "   add %esp, 8\n"
        ;
    } else if (auto varNode = dynamic_cast<ast::Variable*>(r->getChildren()[0])) {
        std::string image = varNode->getSymbol()->getImage();
        std::string location = varNode->getCalculationLocation();
        auto memMap = mMemoryMapVisitor.mProcedureToSymbolsMap[mCurrentProcedure];
        auto type = ast::Type::Types::Undefined;
        auto offset = -1;

        if (memMap.count(image)) {
            // referencing something in this procedure
            offset = memMap[image].offset;
            type = memMap[image].type;

            if (offset < 0) {
                // referencing a local variable
                mOutputS <<
                    "#  READ ( " + location + " ) (LOCAL)\n"
                    "   mov %eax, %ebp\n"
                    "   sub %eax, " + std::to_string(std::abs(offset)) + "\n"
                    "   push %eax\n"
                ;
            } else {
                // referencing a parameter
                mOutputS <<
                    "#  READ ( " + image + " ) (PARAM)\n"
                    "   lea %eax, [ %ebp+" + std::to_string(offset + 12) + " ]\n"
                    "   push [ %eax ]\n"
                ;
            }
        } else {
            // referencing something in main.
            // deref location
            memMap = mMemoryMapVisitor.mProcedureToSymbolsMap["main"];
            offset = memMap[image].offset;
            type = memMap[image].type;

            mOutputS <<
                "   # READ ( " + image + " ) (GLOBAL)\n"
                "   mov %eax, [ %ebp + 8 ]\n"
                "   add %eax, " + std::to_string(offset) + "\n"
                "   push %eax\n"
            ;
        }

        // push correct format string
        if (type == ast::Type::Types::Integer) {
            mOutputS << "   push [ offset .io_format_in + 0 ]\n";
        } else if (type == ast::Type::Types::Float) {
            mOutputS << "   push [ offset .io_format_in + 3 ]\n";
        } else if (type == ast::Type::Types::Character) {
            mOutputS << "   push [ offset .io_format_in + 6 ]\n";
        }
        
        mOutputS <<
            "   call scanf\n"
            "   add %esp, 8\n"
        ;
    }

    mRegisterManager.clear_all();
}

std::string CodeGeneratorVisitor::printConversion(ast::Type::Types from, ast::Type::Types to, std::string loc) {
    constexpr ast::Type::Types FLOAT = ast::Type::Types::Float;
    constexpr ast::Type::Types INT   = ast::Type::Types::Integer;

    auto tempReg = mRegisterManager.get_free_register();
    mRegisterManager.clear_single(loc);

    if (from == INT && to == FLOAT) {
        mOutputS <<
            "#  Converting int to float\n"
            "   push " + loc + "\n"
            "   fild dword ptr [ %esp ]\n"
            "   fstp dword ptr [ %esp ]\n"
            "   pop " + tempReg + "\n"
        ;
    } else if (from == FLOAT && to == INT) {
        mOutputS <<
            "#  Converting float to int\n"
            "   push " + loc + "\n"
            "   fld dword ptr [ %esp ]\n"
            "   fisttp dword ptr [ %esp ]\n"
            "   pop " + tempReg + "\n"
        ;
    }

    return tempReg;
}

std::string CodeGeneratorVisitor::printCompare(ast::Expression::Operation op, ast::Expression* el, ast::Expression* er) {
    constexpr ast::Type::Types FLOAT = ast::Type::Types::Float;
    constexpr ast::Type::Types INT   = ast::Type::Types::Integer;
    constexpr ast::Type::Types CHAR  = ast::Type::Types::Character;
    using OPER = ast::Expression::Operation;
    using TYPE = ast::Type::Types;

    std::string tempReg = mRegisterManager.get_free_register();
    auto labels = mConditionalLabelManager.generateLabelTriple();

    std::string opStr = "";
    std::string jmpStr = "";

    if (el->getType() != er->getType()) {
        // float vs int, something needs to be converted
        if (el->getType() == TYPE::Integer) {
            // left is int, convert
            el->setType(TYPE::Float);
            el->setCalculationLocation(printConversion(TYPE::Integer, TYPE::Float, el->getCalculationLocation()));
        } else {
            // right is int, convert
            er->setType(TYPE::Float);
            er->setCalculationLocation(printConversion(TYPE::Integer, TYPE::Float, er->getCalculationLocation()));
        }
    }

    // both types are the same now
    TYPE type = el->getType();

    if (op == OPER::LessThan) {
        opStr = " < ";
        if (type == TYPE::Integer || type == TYPE::Character) {
            jmpStr = "jl ";
        } else {
            // fcomi uses unsigned jump instructions
            jmpStr = "jb ";
        }
    } else if (op == OPER::LessThanOrEqual) {
        opStr = " <= ";
        if (type == TYPE::Integer || type == TYPE::Character) {
            jmpStr = "jle ";
        } else {
            // fcomi uses unsigned jump instructions
            jmpStr = "jbe ";
        }
    } else if (op == OPER::GreaterThan) {
        opStr = " > ";
        if (type == TYPE::Integer || type == TYPE::Character) {
            jmpStr = "jg ";
        } else {
            // fcomi uses unsigned jump instructions
            jmpStr = "ja ";
        }
    } else if (op == OPER::GreaterThanOrEqual) {
        opStr = " <= ";
        if (type == TYPE::Integer || type == TYPE::Character) {
            jmpStr = "jge ";
        } else {
            // fcomi uses unsigned jump instructions
            jmpStr = "jae ";
        }
    } else if (op == OPER::Equals) {
        opStr = " == ";
        jmpStr = "je ";
    } else if (op == OPER::NotEqual) {
        opStr = " != ";
        jmpStr = "jne ";
    }

    if (el->getType() == er->getType()) {
        if (el->getType() == INT || el->getType() == CHAR) {
            // both ints (or chars)
            mOutputS <<
                "#  " + el->getCalculationLocation() + opStr + er->getCalculationLocation() + " (INT)\n"
                "   mov %eax, " + el->getCalculationLocation() + "\n"
                "   cmp %eax, " + er->getCalculationLocation() + "\n"
            ;
        } else if (el->getType() == FLOAT) {
            // both floats
            mOutputS <<
                "#  " + el->getCalculationLocation() + opStr + er->getCalculationLocation() + " (FLOAT)\n"
                "   push " + er->getCalculationLocation() + "\n"
                "   fld dword ptr [ %esp ]\n"
                "   push " + el->getCalculationLocation() + "\n"
                "   fld dword ptr [ %esp ]\n"
                "   add %esp, 8\n"
                "   fcomip %st(0), %st(1)\n"
                "   fstp %st(0) # to clear stack\n"
            ;
        }

        mOutputS << 
            "   " + jmpStr + labels.labelTrue + "\n"
            "" + labels.labelFalse + ":\n"
            "   mov " + tempReg + ", 0\n"
            "   jmp " + labels.labelEnd + "\n"
            "" + labels.labelTrue + ":\n"
            "   mov " + tempReg + ", 0xffffffff\n"
            "   jmp " + labels.labelEnd + "\n"
            "" + labels.labelEnd + ":\n"
        ;
    }

    mRegisterManager.clear_single(el->getCalculationLocation());
    mRegisterManager.clear_single(er->getCalculationLocation());

    return tempReg;
}

std::string CodeGeneratorVisitor::deriveAddress(std::string addr) {
    if (std::regex_match(addr, std::regex("dword ptr \\[ %.{3}((\\+|-)\\d+)? \\]"))) {
        std::smatch match;
        std::regex_search(addr, match, std::regex("%.{3}((\\+|-)\\d+)?"));
        mOutputS << "#  deriveAddress: " << addr << " -> [ " << match.str(0) << " ]" << std::endl;
        return "[ " + match.str(0) + " ]";
    } else if (std::regex_match(addr, std::regex("\\[ %.{3}((\\+|-)\\d+)? \\]"))) {
        std::smatch match;
        std::regex_search(addr, match, std::regex("\\[ %.{3}((\\+|-)\\d+)? \\]"));
        mOutputS << "#  deriveAddress: " << addr << " -> " << match.str(0) << std::endl;
        return match.str(0);
    }

    return addr;
}