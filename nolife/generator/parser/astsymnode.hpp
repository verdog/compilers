#pragma once

#include "astnode.hpp"

namespace ast {    

    class Symbol : public Base {
        public:
            Symbol(std::string image);

            std::string getImage();
            std::string getKind();

            virtual void accept(Visitor &v);

        private:
            std::string mImage;
    };

} // ast