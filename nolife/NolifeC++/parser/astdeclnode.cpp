#include "astdeclnode.hpp"
#include "visitor.hpp"

namespace ast {

    Declaration::Declaration() {
        mKind = "declaration";
    }

    void Declaration::accept(Visitor &v) {
        v.visit(this);
    }

}