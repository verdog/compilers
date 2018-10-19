#include "astsymnode.hpp"

namespace ast {
    
    Symbol::Symbol(std::string image) 
    : Base()
    , mImage {image}
    {
        mKind = "symbol";
    }

} // ast
