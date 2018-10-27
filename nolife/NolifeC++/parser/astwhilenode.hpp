#pragma once

#include "aststmtnode.hpp"

namespace ast {

    class Expression;

    class While : public Statement {
        public:
            While(Expression* e, Statement *s);
    };

} // ast