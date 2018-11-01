#include "aststmtnode.hpp"
#include "visitor.hpp"

namespace ast {

    Statement::Statement() {
        mKind = "statement";
    }

    void Statement::accept(Visitor &v) {
        v.visit(this);
    }

} // ast