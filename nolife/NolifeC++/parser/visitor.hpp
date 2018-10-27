#pragma once

#include "astnode.hpp"

#include <iostream>
#include <string>

class Visitor {
    public:
        virtual void visit(ast::Base* b) = 0;
    private:
};