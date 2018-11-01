#include "astarrayaccessnode.hpp"
#include "visitor.hpp"

namespace ast {

    ArrayAccess::ArrayAccess(Symbol* s, Expression* e) 
    : Variable(s)
    {
        mKind = "arrayaccess";
        addChild(e);
    }

    void ArrayAccess::accept(Visitor &v) {
        v.visit(this);
    }

    Expression* ArrayAccess::getExpression() {
        if (mChildren.size() >= 2) {
            return dynamic_cast<Expression*>(mChildren[1]);
        } else {
            return nullptr;
        }
    }
} // ast