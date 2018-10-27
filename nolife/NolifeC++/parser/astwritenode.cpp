#include "astwritenode.hpp"
#include "astexpressionnode.hpp"
#include "astconstantnode.hpp"
#include "visitor.hpp"

namespace ast {

    Write::Write(Expression *e) {
        mKind = "write";
        addChild(e);
    }

    Write::Write(Constant* c) {
        mKind = "write";
        addChild(c);
    }

    void Write::accept(Visitor &v) {
        v.visit(this);
    }

} // ast
