#include "astassignnode.hpp"

namespace ast {

    Assignment::Assignment(Variable* v, Expression* e)
    : Binary(v, e)
    {
        mKind = "assignment";
    }

} // ast