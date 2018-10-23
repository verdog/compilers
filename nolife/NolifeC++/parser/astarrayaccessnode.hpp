#pragma once

#include "astvariablenode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    class ArrayAccess : public Variable {
        public:
            ArrayAccess(Symbol* sym, Expression* e);
        private:
    };

} // ast