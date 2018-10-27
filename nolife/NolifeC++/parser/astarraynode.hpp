#pragma once

#include "asttypenode.hpp"

namespace ast {

    class Array : public Type {
        public:
            Array();
            Array* clone();
            Type::Types getType();
            void setSymbol(Symbol* s);
            void setBounds(Symbol* min, Symbol* max);
            void addChild(Base* b) = delete;

            virtual void accept(Visitor &v);
    };

} // ast