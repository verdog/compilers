#include "astcompoundstmtnode.hpp"
#include "visitor.hpp"

namespace ast {

    CompoundStatement::CompoundStatement() {
        mKind = "compound statement";
    }

    void CompoundStatement::accept(Visitor &v) {
        v.visit(this);
    }
    
} // ast
