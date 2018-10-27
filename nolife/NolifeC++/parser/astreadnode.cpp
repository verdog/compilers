#include "astreadnode.hpp"
#include "astvariablenode.hpp"

namespace ast {

    Read::Read(Variable* v) {
        mKind = "read";
        
        addChild(v);
    }

} // ast 