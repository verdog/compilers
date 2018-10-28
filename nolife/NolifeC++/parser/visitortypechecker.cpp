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
}

void TypeCheckVisitor::pushNewSymbolTable() {
    mSymbolTableStack.push_back(tSymbolTable());
    std::cout << "Created a new symbol table. (number of tables remaining: " << mSymbolTableStack.size() << ")\n";
}

void TypeCheckVisitor::popSymbolTable() {
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

    auto children = d->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            // delegate the bookkeeping to the type nodes.
            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::visit(ast::CompoundStatement* cs) {
    std::cout << "Visited a compound statement node.\n";

    auto children = cs->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
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

        auto symInfo = SymbolInfo(sym->getImage());
        symInfo.type = t->getType();

        writeSymbol(sym->getImage(), symInfo);

    } else if (auto arr = dynamic_cast<ast::Array*>(t->getChild())) {
        std::cout << "  Detected an array.\n";

        auto symInfo = SymbolInfo(arr->getSymbol()->getImage());
        symInfo.type = t->getType();
        symInfo.isArray = true;
        symInfo.arrayLowBound = arr->getLowBound()->getImage();
        symInfo.arrayHighBound = arr->getHighBound()->getImage();

        writeSymbol(arr->getSymbol()->getImage(), symInfo);

    } else if (auto proc = dynamic_cast<ast::Procedure*>(t->getChild())) {
        std::cout << "  Detected a procedure.\n";

        auto symInfo = SymbolInfo(proc->getSymbol()->getImage());
        symInfo.type = t->getType();
        symInfo.isProcedure = true;

        writeSymbol(proc->getSymbol()->getImage(), symInfo);

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

void TypeCheckVisitor::visit(ast::ArrayAccess* aa) {
}

void TypeCheckVisitor::visit(ast::Assignment* a) {
    std::cout << "visited assignment node.\n";

    // visit children to deterimine their type
    auto children = a->getChildren();
    auto left = children[0];
    auto right = children[1];

    left->accept(*this);
    right->accept(*this);

    

}

void TypeCheckVisitor::visit(ast::Call* c) {
    std::cout << "visited call node\n";
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

        if (myType == ast::Type::Types::Undefined) {
            std::cout << "!!!  Type error!\n";
        }

    } else {
        // the expression has a single child which will determine its type.

        if (auto constant = dynamic_cast<ast::Constant*>(e->getChildren()[0])) {
            std::cout << "  Constant detected.\n";
            e->setType(constant->getType());
        } else if (auto var = dynamic_cast<ast::Variable*>(e->getChildren()[0])) {
            std::cout << "  Variable detected.\n";
            std::string symImg = var->getSymbol()->getImage();

            if (symbolExists(symImg)) {
                ast::Type::Types t;
                t = lookupSymbol(symImg).type;
                e->setType(t);
            } else {
                // variable not declared error
            }

        } else if (auto call = dynamic_cast<ast::Call*>(e->getChildren()[0])) {
            std::cout << "  Call detected.\n";
            std::string callImg = call->getSymbol()->getImage();

            if (symbolExists(callImg)) {
                ast::Type::Types t;
                t = lookupSymbol(callImg).type;

                if (t == ast::Type::Types::Void) {
                    // procedure call in an expression error
                } else {
                    e->setType(t);
                }

            } else {
                // function not declared error
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
}

void TypeCheckVisitor::visit(ast::Statement* s) {
    std::cout << "visted a statement node.\n";
}

void TypeCheckVisitor::visit(ast::Variable* v) {
    std::cout << "visited a variable node.\n";
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
        std::cout << "  Procedure" << std::endl;
    }

    if (isArray) {
        std::cout << "  Array: " << arrayLowBound << " .. " << arrayHighBound << std::endl;
    }
}