#pragma once

#include <string>

#include "visitor.hpp"

namespace ast {
    class Base;
}

class PrintVisitor : public Visitor {
    public:
        PrintVisitor();
        
        void visit(ast::Base* b);
    private:
        std::string mIndentString;
        std::string mIndentUnit;
};