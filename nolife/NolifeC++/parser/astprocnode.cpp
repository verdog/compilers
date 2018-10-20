#include "astprocnode.hpp"

namespace ast {

    Procedure::Procedure(Symbol* symNode, 
                Parameters* paramNode, 
                Declaration* declNode,
                CompoundStatement *stmtNode)
    : Program(symNode, declNode, stmtNode)
    {
        mKind = "procedure";

        mChildren.resize(4);

        setParam(paramNode);
    }

    void Procedure::setParam(Parameters* paramNode) {
        mChildren[3] = paramNode;
    }

}