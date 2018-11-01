#include "astreadnode.hpp"
#include "astvariablenode.hpp"
#include "visitor.hpp"

namespace ast {

    Read::Read(Variable* v) {
        mKind = "read";
        
        addChild(v);
    }

    void Read::accept(Visitor &v) {
        v.visit(this);
    }

} // ast 