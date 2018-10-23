#pragma once

#include "astnode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    class Return : public Base {
        public:
            Return(Expression* e);
    };

} // ast