#pragma once

#include <vector>

#include "aststmtnode.hpp"

namespace ast {
    
    class Expression;
    class Clause;

    class Case : public Statement {
        public:
            Case(Expression* e, std::vector<Clause*> &list);
    };

} // ast