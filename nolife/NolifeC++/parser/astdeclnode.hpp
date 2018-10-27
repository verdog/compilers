#pragma once

#include <vector>

#include "astnode.hpp"
#include "asttypenode.hpp"

namespace ast {

    class Declaration : public Base {
        public:
            Declaration();

            virtual void accept(Visitor &v);
        private:
    };

} // ast
