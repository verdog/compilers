#include <iostream>

#include "astreturnnode.hpp"

namespace ast {

    Return::Return(Expression* e) {
        mKind = "return";
        
        addChild(e);
    }

} // ast