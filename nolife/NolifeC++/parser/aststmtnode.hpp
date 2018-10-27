#pragma once

#include "astnode.hpp"

namespace ast {

    class Statement : public Base {
        public:
            Statement();

            virtual void accept(Visitor &v);
        private:
    };

} // ast
