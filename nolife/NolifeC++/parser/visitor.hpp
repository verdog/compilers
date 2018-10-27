#pragma once

#include "astnode.hpp"

#include <iostream>
#include <string>

namespace ast {
    class Program;
    class Declaration;
    class CompoundStatement;
    class Parameters;
    class Symbol;
    class Type;
    class Integer;
    class Float;
    class Character;
    class Void;
}

class Visitor {
    public:
        virtual void visit(ast::Base* b) {};
        virtual void visit(ast::Program* p) {};
        virtual void visit(ast::Declaration* d) {};
        virtual void visit(ast::CompoundStatement* cs) {};
        virtual void visit(ast::Parameters* p) {};
        virtual void visit(ast::Symbol* s) {};
        virtual void visit(ast::Type* t) {};
        virtual void visit(ast::Integer* i) {};
        virtual void visit(ast::Float* f) {};
        virtual void visit(ast::Character* c) {};
        virtual void visit(ast::Void* v) {};
    private: 
};