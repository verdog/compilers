#include "astassignnode.hpp"
#include "visitor.hpp"

namespace ast {

    Assignment::Assignment(Variable* v, Expression* e)
    : Binary(v, e)
    {
        mKind = "assignment";
    }

    void Assignment::accept(Visitor &v) {
        v.visit(this);
    }

    Variable* Assignment::getVariable() {
        if (mChildren.size() > 0) {
            return dynamic_cast<Variable*>(mChildren[0]);
        } else {
            return nullptr;
        }
    }

} // ast