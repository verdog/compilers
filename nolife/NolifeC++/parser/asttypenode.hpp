#pragma once

#include "astnode.hpp"

namespace ast {

    class Type : public Base {
        public:
            enum Types {
                Undefined,
                Void,
                Integer,
                Float,
                Character
            };

            Type();
            virtual Types getType() = 0;
            virtual Type* clone() = 0;
    };

    class Integer : public Type {
        public:
            Integer();
            Type::Types getType();
            Integer* clone();
    };

    class Float : public Type {
        public:
            Float();
            Type::Types getType();
            Float* clone();
    };

    class Character : public Type {
        public:
            Character();
            Type::Types getType();
            Character* clone();
    };

    class Void : public Type {
        public:
            Void();
            Type::Types getType();
            Void* clone();
    };

} // ast
