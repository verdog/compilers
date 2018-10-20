#include "asttypenode.hpp"

namespace ast {
    
    Type::Type() {
        mKind = "type";
    }

    Integer::Integer() {
        mKind = "integer";
    }

    Integer* Integer::clone() {
        return new Integer();
    }

    Type::Types Integer::getType() {
        return Type::Types::Integer;
    }

    Float::Float() {
        mKind = "float";
    }

    Float* Float::clone() {
        return new Float();
    }

    Type::Types Float::getType() {
        return Type::Types::Float;
    }

    Character::Character() {
        mKind = "character";
    }

    Character* Character::clone() {
        return new Character();
    }

    Type::Types Character::getType() {
        return Type::Types::Character;
    }

} // ast
