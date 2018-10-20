#include <iostream>

#include "astreturnnode.hpp"

namespace ast {

    bool Return::addChild(Base* node) {
        if (getChildren().size() < 1) {
            Base::addChild(node);
        } else {
            std::cerr << "Tried to add multiple children to a return node!\n";
            return false;
        }
    }

} // ast