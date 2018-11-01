#pragma once

#include "astnode.hpp"

namespace ast {
    
    class CaseLabels : public Base {
        public:
            CaseLabels();

            virtual void accept(Visitor &v);
    };

} // ast
