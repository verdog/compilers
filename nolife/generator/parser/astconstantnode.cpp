#include "astconstantnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Constant::Constant(std::string image, Type::Types t) 
    : Symbol(image)
    , mType {t}
    , mConstantOffset {-1}
    {
        mKind = "constant";
    }

    void Constant::accept(Visitor &v) {
        v.visit(this);
    }

    Type::Types Constant::getType() {
        return mType;
    }

    std::string Constant::getKind() {
        return Symbol::getKind();
    }

    void Constant::setOffset(int offset) {
        mConstantOffset = offset;
    }
} // ast
