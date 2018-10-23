#include "astvariablenode.hpp"

namespace ast {

    Variable::Variable(Symbol* sym) {
        mKind = "variable";
        addChild(sym);
    }

} // ast