#include "astprognode.hpp"

namespace ast {
    
    Program::Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode)
    {
        mKind = "program";

        addChild(symNode);
        addChild(declNode);
        addChild(stmtNode);
    };

    Program::Program(Symbol* symNode, CompoundStatement* stmtNode)
    : Program(symNode, nullptr, stmtNode)
    {}

} // ast
