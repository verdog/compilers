#pragma once

#include <map>
#include <string>

#include "visitor.hpp"
#include "asttypenode.hpp"

class SymbolInfo {
    public:
        SymbolInfo(std::string id) {
            name = id;
            type = ast::Type::Types::Undefined;
            isArray = false;
            isProcedure = false;
        }

        std::string name;
        ast::Type::Types type;
        bool isArray;
        bool isProcedure;
};

namespace ast {
    class Program;
    class Declaration;
    class CompoundStatement;
    class Parameters;
    class Symbol;
}

class TypeCheckVisitor : public Visitor {
    public:
        void visit(ast::Base* b);
        void visit(ast::Program* p);
        void visit(ast::Declaration* d);
        void visit(ast::CompoundStatement* cs);
        void visit(ast::Parameters* p);
        void visit(ast::Symbol* s);
        void visit(ast::Type* t);
        void visit(ast::Integer* i);
        void visit(ast::Float* f);
        void visit(ast::Character* c);
        void visit(ast::Void* v);
    private:
        std::map<std::string, SymbolInfo> mSymbolTable;
};