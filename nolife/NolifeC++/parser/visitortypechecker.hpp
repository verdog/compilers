#pragma once

#include <map>
#include <string>

#include "visitor.hpp"

#include "astnode.hpp"
#include "astarrayaccessnode.hpp"
#include "astarraynode.hpp"
#include "astassignnode.hpp"
#include "astcallnode.hpp"
#include "astcaselabelsnode.hpp"
#include "astcasenode.hpp"
#include "astclausenode.hpp"
#include "astcompoundstmtnode.hpp"
#include "astconstantnode.hpp"
#include "astdeclnode.hpp"
#include "astexpressionnode.hpp"
#include "astifnode.hpp"
#include "astparamnode.hpp"
#include "astprocnode.hpp"
#include "astprognode.hpp"
#include "astreadnode.hpp"
#include "astreturnnode.hpp"
#include "aststmtnode.hpp"
#include "astsymnode.hpp"
#include "asttypenode.hpp"
#include "astvariablenode.hpp"
#include "astwhilenode.hpp"
#include "astwritenode.hpp"

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