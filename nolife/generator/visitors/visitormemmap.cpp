#include <iostream>
#include <string>

#include "visitormemmap.hpp"

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

MemoryMapVisitor::MemoryMapVisitor(std::ostream& output, std::ostream& log)
: mLogS {log}
, mOutputS {output}
{

}

void MemoryMapVisitor::visitUniversal(ast::Base *b) {
    // mLogS << "(universal)\n";

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void MemoryMapVisitor::visit(ast::Base* b) {
    visitUniversal(b);
}

void MemoryMapVisitor::visit(ast::Program* p) {
    mLogS << "visited program node. (" << p->getSymbol()->getImage() << ")\n";

    mFrameStack.push_back(p->getSymbol()->getImage());

    visitUniversal(p);

    mFrameStack.pop_back();
}

void MemoryMapVisitor::visit(ast::Declaration* d) {



    visitUniversal(d);
}

void MemoryMapVisitor::visit(ast::CompoundStatement* cs) {
    mLogS << "visited compound statement node of " << mFrameStack.back() << ".\n";

    visitUniversal(cs);
}

void MemoryMapVisitor::visit(ast::Parameters* p) {
    visitUniversal(p);
}

void MemoryMapVisitor::visit(ast::Symbol* s) {
    mLogS << "visited symbol node. (" << s->getImage() << ")\n";
    visitUniversal(s);
}

void MemoryMapVisitor::visit(ast::Type* t) {
    visitUniversal(t);
}

void MemoryMapVisitor::visit(ast::Integer* i) {
    visitUniversal(i);
}

void MemoryMapVisitor::visit(ast::Float* f) {
    visitUniversal(f);
}

void MemoryMapVisitor::visit(ast::Character* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Void* v) {
    visitUniversal(v);
}

void MemoryMapVisitor::visit(ast::ArrayAccess* aa) {
    visitUniversal(aa);
}

void MemoryMapVisitor::visit(ast::Array* a) {
    visitUniversal(a);
}

void MemoryMapVisitor::visit(ast::Assignment* a) {
    visitUniversal(a);
}

void MemoryMapVisitor::visit(ast::Call* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void MemoryMapVisitor::visit(ast::Case* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Clause* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Constant* c) {
    mLogS << "visited constant node. (" << c->getImage() << ")\n";
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Expression* e) {
    visitUniversal(e);
}

void MemoryMapVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void MemoryMapVisitor::visit(ast::Procedure* p) {
    mLogS << "visited procedure node. (" << p->getSymbol()->getImage() << ")\n";

    mFrameStack.push_back(p->getSymbol()->getImage());

    visitUniversal(p);

    mFrameStack.pop_back();
}

void MemoryMapVisitor::visit(ast::Return* r) {
    visitUniversal(r);
}

void MemoryMapVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void MemoryMapVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
}

void MemoryMapVisitor::visit(ast::While* w) {
    visitUniversal(w);
}

void MemoryMapVisitor::visit(ast::Write* w) {
    visitUniversal(w);
}

void MemoryMapVisitor::visit(ast::Read* r) {
    visitUniversal(r);
}

void MemoryMapVisitor::dumpOutput(const std::ostream& out) {

}