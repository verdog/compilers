#pragma once

#include "astsymnode.hpp"

namespace ast {
    
    class Constant : public Symbol {
        public:
            Constant(std::string image);

            virtual void accept(Visitor &v);
            std::string getKind();
        private:
    };

} // ast
