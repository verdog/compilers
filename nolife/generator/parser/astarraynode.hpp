#pragma once

#include "asttypenode.hpp"

namespace ast {

    class Constant;

    class Array : public Type {
        public:
            Array();
            Array* clone();
            Type::Types getType();
            void setSymbol(Symbol* s);
            Symbol* getSymbol();
            void setBounds(Constant* min, Constant* max);
            Symbol* getLowBound();
            Symbol* getHighBound();
            int getLength();
            void addChild(Base* b) = delete;

            virtual void accept(Visitor &v);
    };

} // ast