#include <iostream>

#include "astexpressionnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Expression::Expression(Expression::Operation op) {
        mKind = "expression";
        mType = Type::Types::Undefined;
        mConvertedType = Type::Types::Undefined;

        mOperation = op;
        mTempOffset = -1;
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

    void Expression::setConvertedType(Type::Types t) {
        mConvertedType = t;
    }

    Type::Types Expression::getType() {
        return mType;
    }

    Type::Types Expression::getConvertedType() {
        return mConvertedType;
    }

    Variable* Expression::childAsVariable() {
        if (mChildren.size() == 1) {
            return dynamic_cast<Variable*>(mChildren[0]);
        } else {
            return nullptr;
        }
    }

    Constant* Expression::childAsConstant() {
        if (mChildren.size() == 1) {
            return dynamic_cast<Constant*>(mChildren[0]);
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

    int Expression::getTempOffset() {
        return mTempOffset;
    }

    void Expression::setTempOffset(int tempOffset) {
        mTempOffset = tempOffset;
    }

} // ast
