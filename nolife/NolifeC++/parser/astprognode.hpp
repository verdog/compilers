#pragma once

#include "astnode.hpp"
#include "astsymnode.hpp"
#include "astdeclnode.hpp"
#include "astcompoundstmtnode.hpp"

namespace ast {

    class Program : public Base {
        public:
            Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode);
            Program(Symbol* symNode, CompoundStatement* stmtNode);

        private:
    };

} // ast