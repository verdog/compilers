#pragma once

#include "aststmtnode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    class Return : public Statement {
        public:
            Return(Expression* e);
    };

} // ast