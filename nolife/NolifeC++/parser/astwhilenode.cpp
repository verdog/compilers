#include "astwhilenode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    While::While(Expression* e, Statement *s) {
        mKind = "while";
        mChildren.resize(2);

        mChildren[0] = e;
        mChildren[1] = s;
    }

} // ast