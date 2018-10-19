#pragma once

#include "astnode.hpp"

namespace ast {

    class Type : public Base {
        public:
            enum Types {
                Undefined,
                Integer,
                Float,
                Character
            };

            Type(Base* node);

            Base* getChild();

            virtual Types getType() = 0;

        protected:
            Base *mChild;
    };

    class Integer : public Type {
        public:
            Type::Types getType();
    };

    class Float : public Type {
        public:
            Type::Types getType();
    };

    class Character : public Type {
        public:
            Type::Types getType();
    };

} // ast
