#include "astvariablenode.hpp"
#include "visitor.hpp"

namespace ast {

    Variable::Variable(Symbol* sym) {
        mKind = "variable";
        addChild(sym);
    }

    void Variable::accept(Visitor &v) {
        v.visit(this);
    }

} // ast