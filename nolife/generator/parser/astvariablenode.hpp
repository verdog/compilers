#pragma once

#include "astnode.hpp"
#include "astsymnode.hpp"

namespace ast {

    class Variable : public Base {
        public:
            Variable(Symbol *sym);

            virtual void accept(Visitor &v);
            Symbol* getSymbol();

            std::string getCalculationLocation();
            void setCalculationLocation(std::string loc);
        private:
            std::string mCalculationLocation;
    };

} // ast