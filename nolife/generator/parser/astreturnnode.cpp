#include <iostream>

#include "astreturnnode.hpp"
#include "visitor.hpp"

namespace ast {

    Return::Return(Expression* e) {
        mKind = "return";
        
        addChild(e);
    }

    void Return::accept(Visitor &v) {
        v.visit(this);
    }

} // ast