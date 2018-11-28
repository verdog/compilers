#pragma once

#include "astvariablenode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    class ArrayAccess : public Variable {
        public:
            ArrayAccess(Symbol* sym, Expression* e);
            virtual void accept(Visitor &v);
            Expression* getExpression();

            std::string getCalculationLocation();
            void setCalculationLocation(std::string loc);
        private:
            std::string mCalculationLocation;
    };

} // ast