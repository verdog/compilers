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

    Symbol* Call::getSymbol() {
        if (mChildren.size() > 0) {
            return dynamic_cast<Symbol*>(mChildren[0]);
        } else {
            return nullptr;
        }
    }

} // ast