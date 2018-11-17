#include <iostream>
#include <string>

#include "visitorcodegenerator.hpp"

#include "../parser/astnode.hpp"
#include "../parser/astarrayaccessnode.hpp"
#include "../parser/astarraynode.hpp"
#include "../parser/astassignnode.hpp"
#include "../parser/astcallnode.hpp"
#include "../parser/astcaselabelsnode.hpp"
#include "../parser/astcasenode.hpp"
#include "../parser/astclausenode.hpp"
#include "../parser/astcompoundstmtnode.hpp"
#include "../parser/astconstantnode.hpp"
#include "../parser/astdeclnode.hpp"
#include "../parser/astexpressionnode.hpp"
#include "../parser/astifnode.hpp"
#include "../parser/astparamnode.hpp"
#include "../parser/astprocnode.hpp"
#include "../parser/astprognode.hpp"
#include "../parser/astreadnode.hpp"
#include "../parser/astreturnnode.hpp"
#include "../parser/aststmtnode.hpp"
#include "../parser/astsymnode.hpp"
#include "../parser/asttypenode.hpp"
#include "../parser/astvariablenode.hpp"
#include "../parser/astwhilenode.hpp"
#include "../parser/astwritenode.hpp"

/**************************
 * Code generator visitor *
 **************************/

CodeGeneratorVisitor::CodeGeneratorVisitor(std::ostream& output, std::ostream& log)
: mLogS {log}
, mOutputS {output}
{

}

void CodeGeneratorVisitor::visitUniversal(ast::Base *b) {
    // mLogS << "(universal)\n";

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void CodeGeneratorVisitor::visit(ast::Base* b) {
    visitUniversal(b);
}

void CodeGeneratorVisitor::visit(ast::Program* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Declaration* d) {
    visitUniversal(d);
}

void CodeGeneratorVisitor::visit(ast::CompoundStatement* cs) {
    visitUniversal(cs);
}

void CodeGeneratorVisitor::visit(ast::Parameters* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Symbol* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Type* t) {
    visitUniversal(t);
}

void CodeGeneratorVisitor::visit(ast::Integer* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Float* f) {
    visitUniversal(f);
}

void CodeGeneratorVisitor::visit(ast::Character* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Void* v) {
    visitUniversal(v);
}

void CodeGeneratorVisitor::visit(ast::ArrayAccess* aa) {
    visitUniversal(aa);
}

void CodeGeneratorVisitor::visit(ast::Array* a) {
    visitUniversal(a);
}

void CodeGeneratorVisitor::visit(ast::Assignment* a) {
    visitUniversal(a);
}

void CodeGeneratorVisitor::visit(ast::Call* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void CodeGeneratorVisitor::visit(ast::Case* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Clause* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Constant* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Expression* e) {
    visitUniversal(e);
}

void CodeGeneratorVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Procedure* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Return* r) {
    visitUniversal(r);
}

void CodeGeneratorVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
}

void CodeGeneratorVisitor::visit(ast::While* w) {
    visitUniversal(w);
}

void CodeGeneratorVisitor::visit(ast::Write* w) {
    visitUniversal(w);
}

void CodeGeneratorVisitor::visit(ast::Read* r) {
    visitUniversal(r);
}
