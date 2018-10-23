#include "astcallnode.hpp"

namespace ast {

    Call::Call(Symbol* s) {
        mKind = "call";

        addChild(s);
    }

} // ast