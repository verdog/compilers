#include <iostream>

#include "astarraynode.hpp"
#include "astsymnode.hpp"

namespace ast {

    Array::Array() 
    : Type::Type()
    {
        mKind = "array";

        std::cout << "  Array created.\n";

        mChildren.resize(3);
    }

    Array* Array::clone() {
        auto clone = new Array();

        auto symbol = dynamic_cast<Symbol*>(mChildren[0]);
        auto min = dynamic_cast<Symbol*>(mChildren[1]);
        auto max = dynamic_cast<Symbol*>(mChildren[2]);

        if (symbol == nullptr) {
            // clone.setChild(nullptr)
        } else {
            clone->setSymbol(new Symbol(*symbol));
        }

        if (min == nullptr || max == nullptr) {
            std::cout << "Something is afoot in Array::clone()!\n";
        } else {
            clone->setBounds(new Symbol(*min), new Symbol(*max));
        }

        return clone;
    }

    Type::Types Array::getType() {
        return Type::Types::Undefined;
    }

    void Array::setSymbol(Symbol* s) {
        mChildren[0] = s;
    }

    void Array::setBounds(Symbol* min, Symbol* max) {
        mChildren[1] = min;
        mChildren[2] = max;
    }

}