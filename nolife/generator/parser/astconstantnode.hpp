#pragma once

#include "astsymnode.hpp"
#include "asttypenode.hpp"

namespace ast {
    
    class Constant : public Symbol {
        public:
            Constant(std::string image, Type::Types t);

            virtual void accept(Visitor &v);
            std::string getKind();
            Type::Types getType();
        private:
            Type::Types mType;
    };

} // ast
