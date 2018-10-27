#include "astwritenode.hpp"
#include "astexpressionnode.hpp"
#include "astconstantnode.hpp"

namespace ast {

    Write::Write(Expression *e) {
        mKind = "write";
        addChild(e);
    }

    Write::Write(Constant* c) {
        mKind = "write";
        addChild(c);
    }

} // ast
