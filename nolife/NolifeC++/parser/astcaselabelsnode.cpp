#include "astcaselabelsnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    CaseLabels::CaseLabels() {
        mKind = "case labels";
    }

    void CaseLabels::accept(Visitor &v) {
        v.visit(this);
    }

} // ast
