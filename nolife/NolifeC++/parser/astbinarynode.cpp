#include "astbinarynode.hpp"

namespace ast {

    Binary::Binary(Base* l, Base* r) {
        mKind = "binary";

        addChild(l);
        addChild(r);
    }

}