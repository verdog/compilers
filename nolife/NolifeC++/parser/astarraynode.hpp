#pragma once

#include "asttypenode.hpp"

namespace ast {

    class Array : public Type {
        public:
            Array();
            Array* clone();
            Type::Types getType();
            void setSymbol(Symbol* s);
            Symbol* getSymbol();
            void setBounds(Symbol* min, Symbol* max);
            Symbol* getLowBound();
            Symbol* getHighBound();
            void addChild(Base* b) = delete;

            virtual void accept(Visitor &v);
    };

} // ast