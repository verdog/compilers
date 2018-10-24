#include <iostream>

#include "astexpressionnode.hpp"

namespace ast {
    
    Expression::Expression(Expression::Operation op) {
        mKind = "expression";

        mOperation = op;
    }

    Expression::Expression(Variable *var) 
    : mOperation { Operation::Noop }
    {
        mKind = "expression";
        
        addChild(var);
    }

    Expression::Expression(Symbol *sym) 
    : mOperation { Operation::Noop }
    {
        mKind = "expression";
        
        addChild(sym);
    }

    Expression::Expression(Call *call) 
    : mOperation { Operation::Noop }
    {
        mKind = "expression";
        
        addChild(call);
    }

    Expression::Expression(Constant *constant) 
    : mOperation { Operation::Noop }
    {
        mKind = "expression";
        
        addChild(constant);
    }

    Expression::Operation Expression::getOperation() {
        return mOperation;
    }

} // ast
