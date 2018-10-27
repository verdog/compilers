#include "astconstantnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Constant::Constant(std::string image) 
    : Symbol(image)
    {
        mKind = "constant";
    }

    void Constant::accept(Visitor &v) {
        v.visit(this);
    }

    std::string Constant::getKind() {
        return Symbol::getKind();
    }
} // ast
