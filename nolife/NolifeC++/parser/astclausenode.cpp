#include "astclausenode.hpp"
#include "astcaselabelsnode.hpp"
#include "aststmtnode.hpp"

namespace ast {

    Clause::Clause(CaseLabels* cl, Statement* s) {
        mKind = "clause";

        mChildren.resize(2);

        mChildren[0] = cl;
        mChildren[1] = s;
    }

} // ast