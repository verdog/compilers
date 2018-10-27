#include "astnode.hpp"
#include "visitor.hpp"

namespace ast {
    
    void Base::accept(Visitor &v) {
        v.visit(this);
    }

    bool Base::addChild(Base* node) {
        mChildren.push_back(node);
        return true;
    }

    std::vector<Base*>& Base::getChildren() {
        return mChildren;
    }

    std::string Base::getKind() const {
        return mKind;
    }

} // ast