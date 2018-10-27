#pragma once

#include "aststmtnode.hpp"
#include "astsymnode.hpp"

namespace ast {

    class Call : public Statement {
        public:
            Call(Symbol* s);

            virtual void accept(Visitor &v);
        private:
    };

} // ast