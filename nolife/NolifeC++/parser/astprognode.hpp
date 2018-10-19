#pragma once

#include "astnode.hpp"
#include "astsymnode.hpp"
#include "astdeclnode.hpp"
#include "aststmtnode.hpp"

namespace ast {

    class Program : public Base {
        public:
            Program(Symbol* symNode, Declaration* declNode, CompoundStatement* stmtNode);
            Program(Symbol* symNode, CompoundStatement* stmtNode);

        private:
            Symbol* mSymbolNode;
            Declaration* mDeclarationNode;
            CompoundStatement* mCompoundStatement;
    };

} // ast