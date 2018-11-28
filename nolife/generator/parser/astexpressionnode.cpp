#include <iostream>

#include "astexpressionnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Expression::Expression(Expression::Operation op) {
        mKind = "expression";
        mType = Type::Types::Undefined;

        mOperation = op;
    }

    Expression::Expression(Variable *var) 
    : mOperation { Operation::Noop }
    , mType { Type::Types::Undefined }
    {
        mKind = "expression";
        
        addChild(var);
    }

    Expression::Expression(Symbol *sym) 
    : mOperation { Operation::Noop }
    , mType { Type::Types::Undefined }
    {
        mKind = "expression";
        
        addChild(sym);
    }

    Expression::Expression(Call *call) 
    : mOperation { Operation::Noop }
    , mType { Type::Types::Undefined }
    {
        mKind = "expression";
        
        addChild(call);
    }

    Expression::Expression(Constant *constant) 
    : mOperation { Operation::Noop }
    , mType { Type::Types::Undefined }
    {
        mKind = "expression";
        
        addChild(constant);
    }

    Expression::Operation Expression::getOperation() {
        return mOperation;
    }

    void Expression::setType(Type::Types t) {
        mType = t;
    }

    Type::Types Expression::getType() {
        return mType;
    }

    Variable* Expression::childAsVariable() {
        if (mChildren.size() == 1) {
            return dynamic_cast<Variable*>(mChildren[0]);
        } else {
            return nullptr;
        }
    }

    void Expression::accept(Visitor &v) {
        v.visit(this);
    }

    std::string Expression::getCalculationLocation() {
        return mCalculationLocation;
    }
    
    void Expression::setCalculationLocation(std::string location) {
        mCalculationLocation = location;
    }

} // ast
