#pragma once

#include "astnode.hpp"

namespace ast {

    class Binary : public Base {
        public:
            Binary(Base* l, Base* r);

            Base* getLeft();
            Base* getRight();
        private:
    };

} // ast