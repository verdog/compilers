#include <iostream>

#include "astreturnnode.hpp"

namespace ast {

    Return::Return(Expression* e) {
        addChild(e);
    }

} // ast