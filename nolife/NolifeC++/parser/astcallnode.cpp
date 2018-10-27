#include "astcallnode.hpp"
#include "visitor.hpp"

namespace ast {

    Call::Call(Symbol* s) {
        mKind = "call";

        addChild(s);
    }

    void Call::accept(Visitor &v) {
        v.visit(this);
    }

} // ast