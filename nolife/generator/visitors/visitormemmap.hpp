#pragma once

#include <iostream>
#include <map>

#include "../visitors/visitor.hpp"
#include "../parser/asttypenode.hpp"

class MemoryInfo {
    public:
        MemoryInfo();
        int offset;
        bool isArray;
        int upperOffset;
        int lowerOffset;
        ast::Type::Types type;
        std::string lowBoundString;
};

class MemoryMapVisitor : public Visitor {
    friend class CodeGeneratorVisitor;
    public:
        MemoryMapVisitor(std::ostream& output, std::ostream& log);

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

        std::ostream& mOutputS;
        void dumpOutput(std::ostream& out);
    private:
        using tSymbolToInfoMap = std::map<std::string, MemoryInfo>;
        std::map<std::string, tSymbolToInfoMap> mProcedureToSymbolsMap;
        tSymbolToInfoMap mConstantMap;

        std::vector<std::string> mFrameStack;

        void resetOffsets();
        void incrementVariableOffset();
        void incrementParameterOffset();
        void incrementConstantOffset(int amount);
        int mCurrentVariableOffset;
        int mCurrentParameterOffset;
        int mCurrentConstantOffset;
        
        std::ostream& mLogS;
};