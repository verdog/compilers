#pragma once

#include "astnode.hpp"

namespace ast {    

    class Symbol : public Base {
        public:
            Symbol(std::string image);

            std::string getImage();

        private:
            std::string mImage;
    };

} // ast