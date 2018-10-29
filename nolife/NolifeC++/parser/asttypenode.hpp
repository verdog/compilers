#pragma once

#include "astnode.hpp"

namespace ast {

    class Procedure;
    class Symbol;
    class Array;

    class Type : public Base {
        public:
            enum class Types {
                Undefined,  // "Undefined" must be listed first.
                            // There is some reliance on the default value of 
                            // Types being undefined.
                Float,
                Void,
                Integer,
                Character,
                StringConstant,
            };

            Type();
            virtual Types getType() = 0;
            virtual Type* clone() = 0;
            void setSymbol(Symbol* s);
            void setFunc(Procedure* p);
            void setArray(Array* a);
            Base* getChild();
            Procedure* childAsProcedure();
            Symbol* childAsSymbol();

            virtual void accept(Visitor &v);
        protected:
    };

    class Integer : public Type {
        public:
            Integer();
            Type::Types getType();
            Integer* clone();

            virtual void accept(Visitor &v);
    };

    class Float : public Type {
        public:
            Float();
            Type::Types getType();
            Float* clone();

            virtual void accept(Visitor &v);
    };

    class Character : public Type {
        public:
            Character();
            Type::Types getType();
            Character* clone();

            virtual void accept(Visitor &v);
    };

    class Void : public Type {
        public:
            Void();
            Type::Types getType();
            Void* clone();

            virtual void accept(Visitor &v);
    };

    std::string typeToString(Type::Types t);

} // ast
