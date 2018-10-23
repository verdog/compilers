#include "astconstantnode.hpp"

namespace ast {
    
    Constant::Constant(std::string image) 
    : Symbol(image)
    {
        mKind = "constant";
    }

} // ast
