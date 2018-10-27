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

} // ast