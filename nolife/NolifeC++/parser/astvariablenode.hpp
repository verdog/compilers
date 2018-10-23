#pragma once

#include "astnode.hpp"
#include "astsymnode.hpp"

namespace ast {

    class Variable : public Base {
        public:
            Variable(Symbol *sym);
        private:
    };

} // ast