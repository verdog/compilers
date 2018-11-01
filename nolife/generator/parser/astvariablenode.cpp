#include "astvariablenode.hpp"
#include "visitor.hpp"

namespace ast {

    Variable::Variable(Symbol* sym) {
        mKind = "variable";
        addChild(sym);
    }

    Symbol* Variable::getSymbol() {
        if (mChildren.size() > 0) {
            return dynamic_cast<Symbol*>(mChildren[0]);
        } else {
            return nullptr;
        }
    }

    void Variable::accept(Visitor &v) {
        v.visit(this);
    }

} // ast