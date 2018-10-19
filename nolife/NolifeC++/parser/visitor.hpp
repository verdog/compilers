#pragma once

#include <iostream>
#include <string>

namespace ast
{
    class Base;
} // ast

class Visitor {
    public:
        virtual std::string visit(ast::Base *n);
    private:
};

std::string Visitor::visit(ast::Base *n) {
    std::cout << n->getKind() << std::endl;
};