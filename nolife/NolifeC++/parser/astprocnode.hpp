#pragma once

#include "astprognode.hpp"
#include "astparamnode.hpp"

namespace ast {

    // a program node, but with parameters.
    class Procedure : public Program {
        public:
            Procedure(Symbol* symNode, 
                Parameters* paramNode, 
                Declaration* declNode,
                CompoundStatement *stmtNode);

            void setParam(Parameters* paramNode);

            virtual void accept(Visitor &v);
        private:
    };

} // ast