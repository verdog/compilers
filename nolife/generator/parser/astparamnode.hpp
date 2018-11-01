#pragma once

#include "astnode.hpp"

namespace ast {

    class Parameters : public Base {
        public:
            Parameters();

            virtual void accept(Visitor &v);
        private:
    };

} // ast