#include <iostream>

#include "visitortypechecker.hpp"

#include "astnode.hpp"
#include "astarrayaccessnode.hpp"
#include "astarraynode.hpp"
#include "astassignnode.hpp"
#include "astcallnode.hpp"
#include "astcaselabelsnode.hpp"
#include "astcasenode.hpp"
#include "astclausenode.hpp"
#include "astcompoundstmtnode.hpp"
#include "astconstantnode.hpp"
#include "astdeclnode.hpp"
#include "astexpressionnode.hpp"
#include "astifnode.hpp"
#include "astparamnode.hpp"
#include "astprocnode.hpp"
#include "astprognode.hpp"
#include "astreadnode.hpp"
#include "astreturnnode.hpp"
#include "aststmtnode.hpp"
#include "astsymnode.hpp"
#include "asttypenode.hpp"
#include "astvariablenode.hpp"
#include "astwhilenode.hpp"
#include "astwritenode.hpp"

TypeCheckVisitor::TypeCheckVisitor() {
    using TypePair = std::pair<ast::Type::Types, ast::Type::Types>;

    constexpr ast::Type::Types INT = ast::Type::Types::Integer;
    constexpr ast::Type::Types FLOAT = ast::Type::Types::Float;
    constexpr ast::Type::Types CHAR = ast::Type::Types::Character;
    constexpr ast::Type::Types ERROR = ast::Type::Types::Undefined;

    // define the type lookup tables.

    tTypeCompatibilityTable arithTable;
    arithTable[TypePair(INT,     INT)] = INT;
    arithTable[TypePair(INT,   FLOAT)] = FLOAT;
    arithTable[TypePair(FLOAT,   INT)] = FLOAT;
    arithTable[TypePair(FLOAT, FLOAT)] = FLOAT;

    tTypeCompatibilityTable logTable;
    logTable[TypePair(CHAR, CHAR)] = CHAR;
    logTable[TypePair(CHAR, INT)] = ERROR;
    logTable[TypePair(CHAR, FLOAT)] = ERROR;
    logTable[TypePair(INT, CHAR)] = ERROR;
    logTable[TypePair(INT, INT)] = INT;
    logTable[TypePair(INT, FLOAT)] = INT;
    logTable[TypePair(FLOAT, CHAR)] = ERROR;
    logTable[TypePair(FLOAT, INT)] = INT;
    logTable[TypePair(FLOAT, FLOAT)] = FLOAT;

    tTypeCompatibilityTable relTable;
    relTable[TypePair(CHAR, CHAR)] = INT;
    relTable[TypePair(CHAR, INT)] = ERROR;
    relTable[TypePair(CHAR, FLOAT)] = ERROR;
    relTable[TypePair(INT, CHAR)] = ERROR;
    relTable[TypePair(INT, INT)] = INT;
    relTable[TypePair(INT, FLOAT)] = INT;
    relTable[TypePair(FLOAT, CHAR)] = ERROR;
    relTable[TypePair(FLOAT, INT)] = INT;
    relTable[TypePair(FLOAT, FLOAT)] = INT;

    tTypeCompatibilityTable modTable;
    modTable[TypePair(INT, INT)] = INT;

    mOpToTableMap[ast::Expression::Operation::Plus] = arithTable;
    mOpToTableMap[ast::Expression::Operation::Minus] = arithTable;
    mOpToTableMap[ast::Expression::Operation::Multiply] = arithTable;
    
    mOpToTableMap[ast::Expression::Operation::Or] = logTable;
    mOpToTableMap[ast::Expression::Operation::And] = logTable;

    mOpToTableMap[ast::Expression::Operation::LessThan] = relTable;
    mOpToTableMap[ast::Expression::Operation::LessThanOrEqual] = relTable;
    mOpToTableMap[ast::Expression::Operation::GreaterThan] = relTable;
    mOpToTableMap[ast::Expression::Operation::GreaterThanOrEqual] = relTable;
    mOpToTableMap[ast::Expression::Operation::Equals] = relTable;
    mOpToTableMap[ast::Expression::Operation::NotEqual] = relTable;

    mOpToTableMap[ast::Expression::Operation::Modulo] = modTable;

    mAssignmentConversionTable[TypePair(INT, INT)] = INT;
    mAssignmentConversionTable[TypePair(INT, FLOAT)] = INT;
    mAssignmentConversionTable[TypePair(INT, CHAR)] = ERROR;
    mAssignmentConversionTable[TypePair(FLOAT, INT)] = FLOAT;
    mAssignmentConversionTable[TypePair(FLOAT, FLOAT)] = FLOAT;
    mAssignmentConversionTable[TypePair(FLOAT, CHAR)] = ERROR;
    mAssignmentConversionTable[TypePair(CHAR, INT)] = ERROR;
    mAssignmentConversionTable[TypePair(CHAR, FLOAT)] = ERROR;
    mAssignmentConversionTable[TypePair(CHAR, CHAR)] = CHAR;
}

void TypeCheckVisitor::pushNewSymbolTable() {
    mSymbolTableStack.push_back(tSymbolTable());
    std::cout << "Created a new symbol table. (number of tables remaining: " << mSymbolTableStack.size() << ")\n";
}

void TypeCheckVisitor::popSymbolTable() {
    auto table = mSymbolTableStack.back();

    for (auto pair : table) {
        auto info = pair.second;

        if (!info.isProcedure && info.referenceCount < 1) {
            std::cout << "!!!  Error: symbol \"" << info.name << "\" declared but never referenced.\n";
        }
    }

    mSymbolTableStack.pop_back();
    std::cout << "Destroyed top symbol table. (number of tables remaining: " << mSymbolTableStack.size() << ")\n";
}

void TypeCheckVisitor::writeSymbol(std::string key, SymbolInfo value) {
    auto& topTable = mSymbolTableStack.back();
    topTable[key] = value;
    std::cout << "  - inserted \"" << key << "\" into topmost table.\n";
}

bool TypeCheckVisitor::symbolExists(std::string key) {
    for (auto it = mSymbolTableStack.rbegin(); it != mSymbolTableStack.rend(); ++it) {
        auto& table = *it;
        if (table.count(key) != 0) {
            return true;
        }
    }

    return false;
}

SymbolInfo& TypeCheckVisitor::lookupSymbol(std::string key) {
    if (!symbolExists(key)) {
        throw "Symbol " + key + " does not exist in any symbol table.";
    }

    for (auto it = mSymbolTableStack.rbegin(); it != mSymbolTableStack.rend(); ++it) {
        auto& table = *it;
        if (table.count(key) != 0) {
            return table[key];
        }
    }
}

ast::Type::Types TypeCheckVisitor::getCombinedType(ast::Type::Types t1, ast::Type::Types t2, ast::Expression::Operation op) {
    using TypePair = std::pair<ast::Type::Types, ast::Type::Types>;

    if (op == ast::Expression::Operation::Not) {
        std::cout << "Since NOT is a unary operation, check it before calling the function.\n";
        return ast::Type::Types::Undefined;
    } else if (t1 == ast::Type::Types::Undefined && t2 == ast::Type::Types::Undefined) {
        // any + any = any
        return ast::Type::Types::Undefined;
    } else if (t1 == ast::Type::Types::Undefined) {
        // any + something = something
        return t2;
    } else if (t2 == ast::Type::Types::Undefined) {
        // something + any = something
        return t1;
    } else {
        if (mOpToTableMap.count(op)) {
            auto& table = mOpToTableMap[op];
            return table[TypePair(t1, t2)];
        } else {
            std::cout << "No known table for operation " << op << "!\n";
            return ast::Type::Types::Undefined;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

void TypeCheckVisitor::visit(ast::Base* b) {
    std::cout << "Visited a base node.\n";
}

void TypeCheckVisitor::visit(ast::Program* p) {
    std::cout << "Visited a program node.\n";

    // create new symbol table
    pushNewSymbolTable();

    // store info about the program
    std::string programName = p->getSymbol()->getImage();

    SymbolInfo programInfo = SymbolInfo(programName);
    programInfo.isProcedure = true;

    writeSymbol(programName, programInfo);

    // visit the symbol
    p->getSymbol()->accept(*this);

    // process declarations
    if (p->getDecl()) { // exists
        p->getDecl()->accept(*this);
    } else {
        std::cout << programName << " has no decls.\n";
    }

    // process compound statement
    if (p->getCompoundStatement()) { // exists
        p->getCompoundStatement()->accept(*this);
    } else {
        std::cout << programName << " has no compound statement.\n";
    }

    // dump tables
    std::cout << "Tables after processing the entire program:\n";
    dumpTable();

    // remove symbol table
    popSymbolTable();
}

void TypeCheckVisitor::visit(ast::Declaration* d) {
    std::cout << "visited a decl node.\n";

    registerProcedures(d);

    auto children = d->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            // delegate the bookkeeping to the type nodes.
            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::registerProcedures(ast::Declaration* d) {
    for (auto child : d->getChildren()) {
        auto type = dynamic_cast<ast::Type*>(child);
        if (type != nullptr) {
            if (auto proc = type->childAsProcedure()) {
                // register procedure
                std::cout << "  Detected procedure \"" << proc->getSymbol()->getImage() << "\".\n";

                if (mSymbolTableStack.back().count(proc->getSymbol()->getImage()) == 0) {
                    auto symInfo = SymbolInfo(proc->getSymbol()->getImage());
                    symInfo.type = type->getType();
                    symInfo.isProcedure = true;
                    symInfo.parameters = proc->getParameters();

                    writeSymbol(proc->getSymbol()->getImage(), symInfo);
                } else {
                    // variable already declared in this scope
                    std::cout << "!!!  Error: symbol \"" << proc->getSymbol()->getImage() << "\" was already declared in this scope.\n";
                }
            }
        }
    }
}

void TypeCheckVisitor::visit(ast::CompoundStatement* cs) {
    std::cout << "Visited a compound statement node.\n";

    auto children = cs->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            // check for a function call used as a statement
            if (auto func = dynamic_cast<ast::Call*>(node)) {
                if (symbolExists(func->getSymbol()->getImage())) {
                    auto info = lookupSymbol(func->getSymbol()->getImage());
                    if (info.type != ast::Type::Types::Void) {
                        // since it returns something, it's a function.
                        std::cout << "!!!  Error: symbol \"" << func->getSymbol()->getImage() << "\" is a function, but was used as a procedure.\n";
                    }
                } else {
                    // symbol does not exist.
                    // this gets caught lower in the tree.
                }
            }

            // visit each statement
            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::visit(ast::Parameters* p) {
    std::cout << "visited a parameters node.\n";

    auto children = p->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            // delegate the bookkeeping to the type nodes.
            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::visit(ast::Symbol* s) {
    std::cout << "Visited symbol node \"" << s->getImage() << "\".\n";
}

void TypeCheckVisitor::visit(ast::Type* t) {
    std::cout << "Visited a type node. This probably shouldn't happen.\n";
}

void TypeCheckVisitor::visit_type(ast::Type* t) {
    if (auto sym = dynamic_cast<ast::Symbol*>(t->getChild())) {
        std::cout << "  Detected a symbol.\n";

        if (mSymbolTableStack.back().count(sym->getImage()) == 0) {
            auto symInfo = SymbolInfo(sym->getImage());
            symInfo.type = t->getType();

            writeSymbol(sym->getImage(), symInfo);
        } else {
            // variable already declared in this scope
            std::cout << "!!!  Error: symbol \"" << sym->getImage() << "\" was already declared in this scope.\n";
        }

    } else if (auto arr = dynamic_cast<ast::Array*>(t->getChild())) {
        std::cout << "  Detected an array.\n";

        if (mSymbolTableStack.back().count(arr->getSymbol()->getImage()) == 0) {
            auto symInfo = SymbolInfo(arr->getSymbol()->getImage());
            symInfo.type = t->getType();
            symInfo.isArray = true;
            symInfo.arrayLowBound = arr->getLowBound()->getImage();
            symInfo.arrayHighBound = arr->getHighBound()->getImage();

            writeSymbol(arr->getSymbol()->getImage(), symInfo);
        } else {
            // variable already declared in this scope
            std::cout << "!!!  Error: symbol \"" << sym->getImage() << "\" was already declared in this scope.\n";
        }

    } else if (auto proc = dynamic_cast<ast::Procedure*>(t->getChild())) {
        // procedures should have already been visited
    }

    t->getChild()->accept(*this);
}

void TypeCheckVisitor::visit(ast::Integer* i) {
    std::cout << "Visited an integer node.\n";
    visit_type(i);
}

void TypeCheckVisitor::visit(ast::Float* f) {
    std::cout << "Visited a float node.\n";
    visit_type(f);
}

void TypeCheckVisitor::visit(ast::Character* c) {
    std::cout << "Visited a character node.\n";
    visit_type(c);
}

void TypeCheckVisitor::visit(ast::Void* v) {
    std::cout << "Visited a void node.\n";
    visit_type(v);
}

void TypeCheckVisitor::visit(ast::Array* a) {
    std::cout << "Visited an array node.\n";
}

void TypeCheckVisitor::visit(ast::Assignment* a) {
    using TypePair = std::pair<ast::Type::Types, ast::Type::Types>;

    std::cout << "visited assignment node.\n";

    // visit children to deterimine their type
    auto children = a->getChildren();
    auto left = children[0];
    auto right = dynamic_cast<ast::Expression*>(children[1]);

    left->accept(*this);
    right->accept(*this);

    std::string leftImage = a->getVariable()->getSymbol()->getImage();

    if (symbolExists(leftImage)) {
        auto leftType = lookupSymbol(leftImage).type;
        lookupSymbol(leftImage).referenceCount++;

        auto combineType = mAssignmentConversionTable[TypePair(leftType, right->getType())];

        if (combineType == ast::Type::Types::Undefined) {
            std::cout << "!!!  Error: Invalid types used in an assignment.\n";
        }
    } else {
        // left is undelcared
        // caught when the node is visited
    }
}

void TypeCheckVisitor::visit(ast::Call* c) {
    std::cout << "visited call node\n";

    auto funcName = c->getSymbol()->getImage();
    int paramsNumber = c->getChildren().size() - 1; // subtract the symbol node

    // visit children to derive types

    for (auto node : c->getChildren()) {
        node->accept(*this);
    }

    if (symbolExists(funcName)) {
        auto info = lookupSymbol(funcName);

        if (info.isProcedure) {
            // check if number of arguments/types are correct
            auto params = info.parameters;

            if (params != nullptr) {
                if (params->getChildren().size() != paramsNumber) {
                    std::cout << "!!!  Incorrect number of arguments when calling " << funcName << "!\n";
                } else {
                    // number of arguments is correct. check their type.
                    bool correctTypes = true;
                    for (int i = 0; i < params->getChildren().size(); i++) {
                        auto properType = dynamic_cast<ast::Type*>(params->getChildren()[i])->getType();
                        auto compareType = dynamic_cast<ast::Expression*>(c->getChildren()[i+1])->getType();

                        if (properType != compareType) {
                            correctTypes = false;
                            break;
                        }
                    }

                    if (!correctTypes) {
                        std::cout << "!!!  Incorrect type of arguments when calling " << funcName << "!\n";
                    }
                }
            } else {
                // params = nullptr. this means the procedure accepts no arguments.
                if (paramsNumber != 0) {
                    std::cout << "!!!  Incorrect type of arguments when calling " << funcName << "!\n";
                }
            }
        } else {
            std::cout << "!!!  Symbol \"" << funcName << "\" is not callable!\n";
        }
    } else {
        std::cout << "!!!  Tried to call a function/procedure named \"" << funcName << "\", which was never declared.\n";
    }    
}

void TypeCheckVisitor::visit(ast::CaseLabels* cl) {
}

void TypeCheckVisitor::visit(ast::Case* c) {
}

void TypeCheckVisitor::visit(ast::Clause* c) {
}

void TypeCheckVisitor::visit(ast::Constant* c) {
    std::cout << "visited constant \"" << c->getImage() << "\" (" << ast::typeToString(c->getType()) << ").\n";
}

void TypeCheckVisitor::visit(ast::Expression* e) {
    std::cout << "Visited expression node.\n";

    auto children = e->getChildren();

    if (e->getOperation() == ast::Expression::Operation::Not) {
        // special behavior for not
    } else if (e->getOperation() != ast::Expression::Operation::Noop) {
        // the expression node is some kind of binary expression.
        
        auto left = dynamic_cast<ast::Expression*>(e->getChildren()[0]);
        auto right = dynamic_cast<ast::Expression*>(e->getChildren()[1]);

        left->accept(*this);
        right->accept(*this);

        auto leftType = left->getType();
        auto rightType = right->getType();

        auto myType = getCombinedType(leftType, rightType, e->getOperation());
        e->setType(myType);

        if (myType == ast::Type::Types::Undefined) {
            std::cout << "!!!  Error: Incompatable types in expression.\n";
        }

    } else {
        // the expression has a single child which will determine its type.

        if (auto constant = dynamic_cast<ast::Constant*>(e->getChildren()[0])) {
            std::cout << "  Constant detected.\n";
            e->setType(constant->getType());
            std::cout << "  Set type as: " << ast::typeToString(e->getType()) << "\n";
        } else if (auto var = dynamic_cast<ast::Variable*>(e->getChildren()[0])) {
            std::cout << "  Variable detected.\n";
            std::string symImg = var->getSymbol()->getImage();

            if (symbolExists(symImg)) {
                ast::Type::Types t;
                lookupSymbol(symImg).referenceCount++;
                t = lookupSymbol(symImg).type;
                e->setType(t);
            } else {
                // variable never declared error
                // will be caught when the variable node gets visited
                e->setType(ast::Type::Types::Undefined);
            }

        } else if (auto call = dynamic_cast<ast::Call*>(e->getChildren()[0])) {
            std::cout << "  Call detected.\n";
            std::string callImg = call->getSymbol()->getImage();

            if (symbolExists(callImg)) {
                ast::Type::Types t;
                t = lookupSymbol(callImg).type;

                if (t == ast::Type::Types::Void) {
                    std::cout << "!!!  Error: symbol \"" << call->getSymbol()->getImage() << "\" is a proceedure, but was used as a function.\n";
                    e->setType(ast::Type::Types::Undefined);
                } else {
                    e->setType(t);
                }

            } else {
                // function not declared error
                // will be caught when the call node gets visited
                e->setType(ast::Type::Types::Undefined);
            }
        }

        // visit the child
        e->getChildren()[0]->accept(*this);
    }
}

void TypeCheckVisitor::visit(ast::If* i) {
}

void TypeCheckVisitor::visit(ast::Procedure* p) {
    std::cout << "Visited a procedure node.\n";

    // create new symbol table
    pushNewSymbolTable();

    // visit the symbol
    p->getSymbol()->accept(*this);

    // process parameters
    if (p->getParameters()) { // exists
        p->getParameters()->accept(*this);
    } else {
        std::cout << "procedure \"" << p->getSymbol()->getImage() << "\" has no parameters.\n";
    }

    // process declarations
    if (p->getDecl()) { // exists
        p->getDecl()->accept(*this);
    } else {
        std::cout << "procedure \"" << p->getSymbol()->getImage() << "\" has no decls.\n";
    }

    // process compound statement
    if (p->getCompoundStatement()) { // exists
        p->getCompoundStatement()->accept(*this);
    } else {
        std::cout << "procedure \"" << p->getSymbol()->getImage() << "\" has no compound statement.\n";
    }

    // dump tables
    std::cout << "Tables after processing procedure " << p->getSymbol()->getImage() << ":\n";
    dumpTable();

    // remove symbol table
    popSymbolTable();
}

void TypeCheckVisitor::visit(ast::Return* r) {
    std::cout << "vistied return node.\n";

    r->getChildren()[0]->accept(*this);
}

void TypeCheckVisitor::visit(ast::Statement* s) {
    std::cout << "visted a statement node.\n";
}

void TypeCheckVisitor::visit(ast::Variable* v) {
    std::cout << "visited a variable node.\n";

    auto symbolStr = v->getSymbol()->getImage();

    if (symbolExists(symbolStr)) {
        // nothing else to check for
    } else {
        std::cout << "!!!  Error: Symbol \"" << symbolStr << "\" used but never declared.\n";
    }

    for (auto node : v->getChildren()) {
        node->accept(*this);
    }
}

void TypeCheckVisitor::visit(ast::ArrayAccess* aa) {
    std::cout << "visited an array access node.\n";

    auto symbolStr = aa->getSymbol()->getImage();

    if (symbolExists(symbolStr)) {
        auto info = lookupSymbol(symbolStr);

        // check if symbol is subscriptable in the first place
        if (info.isArray == true) {
            // check if index is within declared bounds, if we can
            auto expr = aa->getExpression();
            if (auto constant = dynamic_cast<ast::Constant*>(expr->getChildren()[0])) {
                auto idx = constant->getImage();

                try {
                    // check if bounds is a string or a number
                    int low = std::stoi(info.arrayLowBound);
                    int high = std::stoi(info.arrayLowBound);
                    int iidx = std::stoi(constant->getImage());

                    if (iidx < low || iidx > high) {
                        std::cout << "!!!  Error: Array index \"" << idx << "\" is out of range of array \"" << symbolStr << "\".\n";
                    }
                } catch (std::invalid_argument) {
                    // it's characters
                    if (idx < info.arrayLowBound || idx > info.arrayHighBound) {
                        std::cout << "!!!  Error: Array index \"" << idx << "\" is out of range of array \"" << symbolStr << "\".\n";
                    }
                }
            }
        } else {
            std::cout << "!!!  Error: Symbol \"" << symbolStr << "\" is not subscriptable.\n";
        }

    } else {
        std::cout << "!!!  Error: Symbol \"" << symbolStr << "\" used but never declared.\n";
    }

    for (auto node : aa->getChildren()) {
        node->accept(*this);
    }
}

void TypeCheckVisitor::visit(ast::While* w) {
}

void TypeCheckVisitor::visit(ast::Write* w) {
}

////////////////////////////////////////////////////////////////////////////////

void TypeCheckVisitor::dumpTable() {
    std::cout << "Symbol table dump (topmost table writen first):\n";
    
    for (auto it = mSymbolTableStack.rbegin(); it != mSymbolTableStack.rend(); ++it) {
        std::cout << "--------- NEW TABLE --------\n";
        auto& table = *it;
        for (auto pair : table) {
            pair.second.dumpInfo();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

void SymbolInfo::dumpInfo() {
    std::cout 
        << name << std::endl
        << "  Type: " << ast::typeToString(type) << std::endl;
    ;

    if (isProcedure) {
        std::string paramString = "(";

        if (parameters != nullptr) {
            for (int i = 0; i < parameters->getChildren().size(); i++) {
                auto type = dynamic_cast<ast::Type*>(parameters->getChildren()[i]);
                if (i == 0) {
                    paramString += ast::typeToString(type->getType());
                } else {
                    paramString += ", " + ast::typeToString(type->getType());
                }
            }
        }

        paramString += ")";

        std::cout << "  Procedure " << paramString << std::endl;
    }

    if (isArray) {
        std::cout << "  Array: " << arrayLowBound << " .. " << arrayHighBound << std::endl;
    }
    
    std::cout << "  Referenced " << referenceCount << " times.\n";
}