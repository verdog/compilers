#include "astarrayaccessnode.hpp"

namespace ast {

    ArrayAccess::ArrayAccess(Symbol* s, Expression* e) 
    : Variable(s)
    {
        mKind = "arrayaccess";
        addChild(e);
    }

} // ast