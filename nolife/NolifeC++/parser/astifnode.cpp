#include "astifnode.hpp"
#include "astexpressionnode.hpp"
#include "visitor.hpp"

namespace ast {

    If::If() {
        mKind = "if";
        mChildren.resize(3);
    }

    If::If(Expression* e, Statement* then, Statement* els) 
    : If()
    {
        mChildren[0] = e;
        mChildren[1] = then;
        mChildren[2] = els;
    }

    void If::setCondition(Expression *e) {
        mChildren[0] = e;
    }

    void If::setThen(Statement *s) {
        mChildren[1] = s;
    }

    void If::setElse(Statement *s) {
        mChildren[2] = s;
    }

    void If::accept(Visitor &v) {
        v.visit(this);
    }

} // ast