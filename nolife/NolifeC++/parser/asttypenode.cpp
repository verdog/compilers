#include "asttypenode.hpp"

namespace ast {
    
    Type::Type(Base* base)
    : mChild {base}
    {}

    Base* Type::getChild() {
        return mChild;
    }

    Type::Types Integer::getType() {
        return Type::Types::Integer;
    }

    Type::Types Float::getType() {
        return Type::Types::Float;
    }

    Type::Types Character::getType() {
        return Type::Types::Character;
    }

} // ast
