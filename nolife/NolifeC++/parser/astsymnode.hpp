#pragma once

#include "astnode.hpp"

namespace ast {    

    class Symbol : public Base {
        public:
            Symbol(std::string image);

        private:
            std::string mImage;
    };

} // ast