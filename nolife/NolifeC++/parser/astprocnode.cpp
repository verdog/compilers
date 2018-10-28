#include <iostream>

#include "astprocnode.hpp"
#include "visitor.hpp"

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
        std::cout << "  Set param.\n";
        mChildren[3] = paramNode;
    }

    Parameters* Procedure::getParameters() {
        if (mChildren.size() >= 3) {
            return dynamic_cast<Parameters*>(mChildren[3]);
        } else {
            return nullptr;
        }
    }

    void Procedure::accept(Visitor &v) {
        v.visit(this);
    }

}