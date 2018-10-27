#pragma once

#include "astnode.hpp"

namespace ast {

    class CaseLabels;
    class Statement;

    class Clause : public Base {
        public:
            Clause(CaseLabels *cl, Statement* s);
    };

} // ast