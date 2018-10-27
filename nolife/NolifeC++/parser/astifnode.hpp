#pragma once

#include "aststmtnode.hpp"

namespace ast {

    class Expression;

    class If : public Statement {
        public:
            If();
            If(Expression *e, Statement *then, Statement *els);

            void setCondition(Expression* e);
            void setThen(Statement* s);
            void setElse(Statement* s);
        private:
    };

} // ast