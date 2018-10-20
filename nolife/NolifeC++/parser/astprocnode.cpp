#include "astprocnode.hpp"

namespace ast {

    Procedure::Procedure(Symbol* symNode, 
                Parameters* paramNode, 
                Declaration* declNode,
                CompoundStatement *stmtNode)
    : Program(symNode, declNode, stmtNode)
    {
        mKind = "proceedure";

        addChild(paramNode);
    }

}