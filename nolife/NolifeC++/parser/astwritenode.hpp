#pragma once

#include "aststmtnode.hpp"

namespace ast {

    class Expression;
    class Constant;

    class Write : public Statement {
        public:
            Write(Expression* e);
            Write(Constant* c);

            virtual void accept(Visitor &v);
    };

} //