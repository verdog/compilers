#pragma once

#include "astbinarynode.hpp"
#include "astvariablenode.hpp"
#include "astexpressionnode.hpp"

namespace ast {

    class Assignment : public Binary {
        public:
            Assignment(Variable* v, Expression* e);

            virtual void accept(Visitor &v);
    };

} // ast