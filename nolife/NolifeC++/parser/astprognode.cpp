#include "astprognode.hpp"

namespace ast {
    
    Program::Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode)
    {
        mKind = "program";

        mChildren.push_back(symNode);
        mChildren.push_back(declNode);
        mChildren.push_back(stmtNode);
    };

    Program::Program(Symbol* symNode, CompoundStatement* stmtNode)
    : Program(symNode, nullptr, stmtNode)
    {}

} // ast
