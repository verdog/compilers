#include <iostream>

#include "visitortypechecker.hpp"

#include "astprognode.hpp"
#include "astdeclnode.hpp"
#include "astparamnode.hpp"
#include "astcompoundstmtnode.hpp"
#include "asttypenode.hpp"

void TypeCheckVisitor::visit(ast::Base* b) {
    std::cout << "Visited a base node.\n";
}

void TypeCheckVisitor::visit(ast::Program* p) {
    std::cout << "Visited a program node.\n";

    auto children = p->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::visit(ast::Declaration* d) {
    std::cout << "visited a decl node.\n";

    auto children = d->getChildren();

    for (auto node : children) {
        if (node != nullptr) {
            if (auto t = dynamic_cast<ast::Type*>(node)) {
                // do some logging
            }

            node->accept(*this);
        }
    }
}

void TypeCheckVisitor::visit(ast::CompoundStatement* cs) {
    std::cout << "visited a compound stmt node.\n";
}

void TypeCheckVisitor::visit(ast::Parameters* p) {
    std::cout << "visited a parameters node.\n";
}

void TypeCheckVisitor::visit(ast::Symbol* s) {
    std::cout << "visited a symbol node.\n";
}

void TypeCheckVisitor::visit(ast::Type* t) {
    std::cout << "type\n";
}

void TypeCheckVisitor::visit(ast::Integer* t) {
    std::cout << "Integer\n";
}

void TypeCheckVisitor::visit(ast::Float* t) {
    std::cout << "Float\n";
}

void TypeCheckVisitor::visit(ast::Character* t) {
    std::cout << "Character\n";
}

void TypeCheckVisitor::visit(ast::Void* t) {
    std::cout << "Void\n";
}
