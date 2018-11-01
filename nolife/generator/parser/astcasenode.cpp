#include "astcasenode.hpp"
#include "astexpressionnode.hpp"
#include "astclausenode.hpp"
#include "visitor.hpp"

namespace ast {

    Case::Case(Expression* e, std::vector<Clause*>* list) {
        mKind = "case";

        addChild(e);

        if (list != nullptr) {
            for (auto clause : *list) {
                addChild(clause);
            }
        }
    }

    void Case::accept(Visitor &v) {
        v.visit(this);
    }
    
} // ast
