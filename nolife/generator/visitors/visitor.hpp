#pragma once

#include "../parser/astnode.hpp"

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
    class ArrayAccess;
    class Array;
    class Assignment;
    class Call;
    class CaseLabels;
    class Case;
    class Clause;
    class Constant;
    class Expression;
    class If;
    class Procedure;
    class Return;
    class Statement;
    class Variable;
    class While;
    class Write;
    class Read;
}

class Visitor {
    public:
        Visitor();
        virtual void visit(ast::Base* b) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Program* p) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Declaration* d) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::CompoundStatement* cs) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Parameters* p) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Symbol* s) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Type* t) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Integer* i) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Float* f) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Character* c) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Void* v) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::ArrayAccess* aa) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Array* a) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Assignment* a) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Call* c) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::CaseLabels* cl) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Case* c) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Clause* c) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Constant* c) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Expression* e) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::If* i) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Procedure* p) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Return* r) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Statement* s) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Variable* v) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::While* w) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Write* w) {std::cout << "this is in the visitor base class.\n"; };
        virtual void visit(ast::Read* r) {std::cout << "this is in the visitor base class.\n"; };
        
        bool mDone;
    private: 
};