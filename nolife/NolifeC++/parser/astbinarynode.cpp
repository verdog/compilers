#include "astbinarynode.hpp"

namespace ast {

    Binary::Binary(Base* l, Base* r) {
        mKind = "binary";

        addChild(l);
        addChild(r);
    }

    Base* Binary::getLeft() {
        return mChildren[0];
    }

    Base* Binary::getRight() {
        return mChildren[1];
    }

}