#include "astparamnode.hpp"
#include "visitor.hpp"

namespace ast {

    Parameters::Parameters() {
        mKind = "parameters";
    }

    void Parameters::accept(Visitor &v) {
        v.visit(this);
    }

} //