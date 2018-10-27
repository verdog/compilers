#include <iostream>

#include "astprognode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Program::Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode)
    {
        mKind = "program";

        mChildren.resize(3);

        setSymbol(symNode);
        setDecl(declNode);
        setCompoundStmt(stmtNode);
    };

    Program::Program(Symbol* symNode, CompoundStatement* stmtNode)
    : Program(symNode, nullptr, stmtNode)
    {}

    void Program::setSymbol(Symbol* symNode) {
        std::cout << "  Set symbol.\n";
        mChildren[0] = symNode;
    }

    void Program::setDecl(Declaration* declNode) {
        std::cout << "  Set decl.\n";
        mChildren[1] = declNode;
    }

    void Program::setCompoundStmt(CompoundStatement* stmtNode) {
        std::cout << "  Set stmt.\n";
        mChildren[2] = stmtNode;
    }

    void Program::accept(Visitor &v) {
        v.visit(this);
    }

} // ast
