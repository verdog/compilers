#pragma once

#include "astnode.hpp"
#include "astcallnode.hpp"
#include "astvariablenode.hpp"
#include "astconstantnode.hpp"
#include "asttypenode.hpp"

namespace ast {
    
    class Expression : public Base {
        public:
            enum Operation {
                // add precedence
                Plus,
                Minus,
                // multiply precedence
                Multiply,
                Modulo,
                // relational precedence
                LessThanOrEqual,
                LessThan,
                GreaterThanOrEqual,
                GreaterThan,
                Equals,
                NotEqual,
                // logical precedence
                And,
                Or,
                Not,

                // used when the expression is not an operation
                Noop
            };

            Expression(Operation op);
            Expression(Variable *var);
            Expression(Symbol *sym);
            Expression(Call *call);
            Expression(Constant *constant);

            Operation getOperation();
            void setType(Type::Types t);
            void setConvertedType(Type::Types t);
            Type::Types getType();
            Type::Types getConvertedType();
            void setCalculationLocation(std::string location);
            std::string getCalculationLocation();

            Variable* childAsVariable();
            Constant* childAsConstant();

            int getTempOffset();
            void setTempOffset(int tempOffset);

            virtual void accept(Visitor &v);
        private:
            Operation mOperation;
            std::string mCalculationLocation;

            Type::Types mType;
            Type::Types mConvertedType;

            int mTempOffset;
    };

} // ast
