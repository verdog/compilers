#include <iostream>
#include <string>

#include "visitorprinter.hpp"

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

PrintVisitor::PrintVisitor() 
: mIndentString {""}
, mIndentUnit {".  "}
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
