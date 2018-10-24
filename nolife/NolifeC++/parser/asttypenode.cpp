#include "asttypenode.hpp"
#include "astsymnode.hpp"
#include "astprocnode.hpp"

namespace ast {
    
    Type::Type() {
        mKind = "type";
    }

    void Type::setSymbol(Symbol* s) {
        Base::addChild(s);
    }

    void Type::setFunc(Procedure* p) {
        Base::addChild(p);
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

    Void::Void() {
        mKind = "void";
    }

    Void* Void::clone() {
        return new Void();
    }

    Type::Types Void::getType() {
        return Type::Types::Void;
    }

} // ast
