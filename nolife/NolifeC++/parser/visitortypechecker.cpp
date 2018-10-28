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
}

void TypeCheckVisitor::visit(ast::Call* c) {
}

void TypeCheckVisitor::visit(ast::CaseLabels* cl) {
}

void TypeCheckVisitor::visit(ast::Case* c) {
}

void TypeCheckVisitor::visit(ast::Clause* c) {
}

void TypeCheckVisitor::visit(ast::Constant* c) {
}

void TypeCheckVisitor::visit(ast::Expression* e) {
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
}

void TypeCheckVisitor::visit(ast::Variable* v) {
}

void TypeCheckVisitor::visit(ast::While* w) {
}

void TypeCheckVisitor::visit(ast::Write* w) {
}

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

////////////////////////////////////////////////////

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