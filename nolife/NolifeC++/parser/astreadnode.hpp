#pragma once

#include "aststmtnode.hpp"

namespace ast {

    class Variable;

    class Read : public Statement {
        public:
            Read(Variable* v);

            virtual void accept(Visitor &v);
    };

} // ast