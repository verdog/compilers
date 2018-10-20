#include "astassignnode.hpp"

namespace ast {

    Assign::Assign(Base* l, Base* r)
    : Binary(l, r)
    {
        mKind = "assign";
    }

} // ast