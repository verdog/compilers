#include <iostream>
#include <string>

#include "visitorprinter.hpp"
#include "astnode.hpp"

PrintVisitor::PrintVisitor() 
: mIndentString {""}
, mIndentUnit {".  "}
{}

void PrintVisitor::visit(ast::Base* b) {
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