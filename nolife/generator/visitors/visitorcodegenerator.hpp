#pragma once

#include <iostream>
#include <string>
#include <map>
#include <queue>

#include "../parser/asttypenode.hpp"
#include "../parser/astexpressionnode.hpp"
#include "../visitors/visitor.hpp"
#include "../utilities/registermanager.hpp"
#include "../utilities/conditionallabelmanager.hpp"
#include "../utilities/caselabelmanager.hpp"

class TypeCheckVisitor;
class MemoryMapVisitor;

class CodeGeneratorVisitor : public Visitor {
    public:
        CodeGeneratorVisitor(
            std::ostream& output, 
            std::ostream& log,
            TypeCheckVisitor& typeCheckVisitor,
            MemoryMapVisitor& memoryMapVisitor
        );

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
        void visit(ast::ArrayAccess* aa);
        void visit(ast::Array* a);
        void visit(ast::Assignment* a);
        void visit(ast::Call* c);
        void visit(ast::CaseLabels* cl);
        void visit(ast::Case* c);
        void visit(ast::Clause* c);
        void visit(ast::Constant* c);
        void visit(ast::Expression* e);
        void visit(ast::If* i);
        void visit(ast::Procedure* p);
        void visit(ast::Return* r);
        void visit(ast::Statement* s);
        void visit(ast::Variable* v);
        void visit(ast::While* w);
        void visit(ast::Write* w);
        void visit(ast::Read* r);

        void visitUniversal(ast::Base* b);

    private:
        void initialize();
        void finalize();

        std::string printConversion(ast::Type::Types from, ast::Type::Types to, std::string loc);
        std::string printCompare(ast::Expression::Operation op, ast::Expression* el, ast::Expression* er);
        std::string deriveAddress(std::string loc);

        std::ostream& mLogS;
        std::ostream& mOutputS;

        TypeCheckVisitor& mTypeCheckVisitor;
        MemoryMapVisitor& mMemoryMapVisitor;

        std::string mCurrentProcedure;

        RegisterManager mRegisterManager;
        ConditionalLabelManager mConditionalLabelManager;
        CaseLabelManager mCaseLabelManager;

        std::queue<ast::Procedure*> mProcQueue;

};