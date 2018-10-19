#include "astprognode.hpp"

namespace ast {
    
    Program::Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode)
    : mSymbolNode {symNode}
    , mDeclarationNode {declNode}
    , mCompoundStatement {stmtNode}
    {
        mKind = "program";
    };

    Program::Program(Symbol* symNode, CompoundStatement* stmtNode)
    : Program(symNode, nullptr, stmtNode)
    {}

} // ast
