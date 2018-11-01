#include <iostream>
#include <string>

#include "visitorprinter.hpp"

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

PrintVisitor::PrintVisitor() 
: mIndentString {""}
, mIndentUnit {". "}
{}

void PrintVisitor::visit_universal(ast::Base* b) {
    std::cout << mIndentString << b->getKind() << std::endl;

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            mIndentString += mIndentUnit;
            node->accept(*this);
        }
    }

    if (mIndentString.size() > 0) {
        mIndentString.resize(mIndentString.size() - mIndentUnit.size());
    }
}

void PrintVisitor::visit(ast::Base* b) {
    visit_universal(b);
}

void PrintVisitor::visit(ast::Program* p) {
    visit_universal(p);
}

void PrintVisitor::visit(ast::Declaration* d) {
    visit_universal(d);
}

void PrintVisitor::visit(ast::CompoundStatement* cs) {
    visit_universal(cs);
}

void PrintVisitor::visit(ast::Parameters* p) {
    visit_universal(p);
}

void PrintVisitor::visit(ast::Symbol* s) {
    visit_universal(s);
}

void PrintVisitor::visit(ast::Type* t) {
    visit_universal(t);
}

void PrintVisitor::visit(ast::Integer* i) {
    visit_universal(i);
}

void PrintVisitor::visit(ast::Float* f) {
    visit_universal(f);
}

void PrintVisitor::visit(ast::Character* c) {
    visit_universal(c);
}

void PrintVisitor::visit(ast::Void* v) {
    visit_universal(v);
}

void PrintVisitor::visit(ast::ArrayAccess* aa) {
    visit_universal(aa);
}

void PrintVisitor::visit(ast::Array* a) {
    visit_universal(a);
}

void PrintVisitor::visit(ast::Assignment* a) {
    visit_universal(a);
}

void PrintVisitor::visit(ast::Call* c) {
    visit_universal(c);
}

void PrintVisitor::visit(ast::CaseLabels* cl) {
    visit_universal(cl);
}

void PrintVisitor::visit(ast::Case* c) {
    visit_universal(c);
}

void PrintVisitor::visit(ast::Clause* c) {
    visit_universal(c);
}

void PrintVisitor::visit(ast::Constant* c) {
    visit_universal(c);
}

void PrintVisitor::visit(ast::Expression* e) {
    visit_universal(e);
}

void PrintVisitor::visit(ast::If* i) {
    visit_universal(i);
}

void PrintVisitor::visit(ast::Procedure* p) {
    visit_universal(p);
}

void PrintVisitor::visit(ast::Return* r) {
    visit_universal(r);
}

void PrintVisitor::visit(ast::Statement* s) {
    visit_universal(s);
}

void PrintVisitor::visit(ast::Variable* v) {
    visit_universal(v);
}

void PrintVisitor::visit(ast::While* w) {
    visit_universal(w);
}

void PrintVisitor::visit(ast::Write* w) {
    visit_universal(w);
}

void PrintVisitor::visit(ast::Read* r) {
    visit_universal(r);
}