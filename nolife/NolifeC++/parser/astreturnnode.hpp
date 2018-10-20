#pragma once

#include "astnode.hpp"

namespace ast {

    class Return : public Base {
        public:
            bool addChild(Base* node);
    };

} // ast