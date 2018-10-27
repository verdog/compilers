#include "astcasenode.hpp"
#include "astexpressionnode.hpp"
#include "astclausenode.hpp"

namespace ast {

    Case::Case(Expression* e, std::vector<Clause*> &list) {
        mKind = "case";

        addChild(e);

        for (auto clause : list) {
            addChild(clause);
        }
    }
    
} // ast
