#include "astsymnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Symbol::Symbol(std::string image) 
    : Base()
    , mImage {image}
    {
        mKind = "symbol";
    }

    std::string Symbol::getImage() {
        return mImage;
    }

    void Symbol::accept(Visitor &v) {
        v.visit(this);
    }

} // ast
