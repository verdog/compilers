#include "astwhilenode.hpp"
#include "astexpressionnode.hpp"
#include "visitor.hpp"

namespace ast {

    While::While(Expression* e, Statement *s) {
        mKind = "while";
        mChildren.resize(2);

        mChildren[0] = e;
        mChildren[1] = s;
    }

    void While::accept(Visitor &v) {
        v.visit(this);
    }

} // ast