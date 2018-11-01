#pragma once

#include "aststmtnode.hpp"

namespace ast {

    class CompoundStatement : public Statement {
        public:
            CompoundStatement();

            virtual void accept(Visitor &v);
        private:
    };

} // ast
