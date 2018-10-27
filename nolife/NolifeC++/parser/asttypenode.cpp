#include <iostream>

#include "asttypenode.hpp"
#include "astsymnode.hpp"
#include "astprocnode.hpp"
#include "astarraynode.hpp"
#include "visitor.hpp"

namespace ast {
    
    Type::Type() {
        mKind = "type";
    }

    void Type::setSymbol(Symbol* s) {
        // if there is a child, it is an array.
        // set the symbol on the array child.
        // otherwise, just add the symbol to the node itself.

        if (mChildren.size() > 0) {
            auto child = dynamic_cast<Array*>(mChildren[0]);
            if (child != nullptr) {
                std::cout << "  Array detected in set symbol.\n";
                child->setSymbol(s);
            }
        } else {
            Base::addChild(s);
        }
    }

    void Type::setFunc(Procedure* p) {
        Base::addChild(p);
    }

    void Type::setArray(Array* a) {
        std::cout << "  Set array!\n";
        if (mChildren.size() > 0) {
            mChildren.clear();
        }
        Base::addChild(a);
    }

    void Type::accept(Visitor &v) {
        v.visit(this);
    }

    Integer::Integer() 
    : Type()
    {
        mKind = "integer";
    }

    Integer* Integer::clone() {
        auto clone = new Integer(*this);
        
        if (mChildren.size() > 0 && mChildren[0] != nullptr) {
            // has and array child
            auto typeChild = dynamic_cast<Array*>(mChildren[0]);

            if (typeChild != nullptr) {
                clone->setArray(typeChild->clone());
            }
        }

        return clone;
    }

    Type::Types Integer::getType() {
        return Type::Types::Integer;
    }

    void Integer::accept(Visitor &v) {
        v.visit(this);
    }

    Float::Float() 
    : Type::Type()
    {
        mKind = "float";
    }

    Float* Float::clone() {
        auto clone = new Float(*this);
        
        if (mChildren.size() > 0 && mChildren[0] != nullptr) {
            // has and array child
            auto typeChild = dynamic_cast<Array*>(mChildren[0]);

            if (typeChild != nullptr) {
                clone->setArray(typeChild->clone());
            }
        }

        return clone;
    }

    Type::Types Float::getType() {
        return Type::Types::Float;
    }

    void Float::accept(Visitor &v) {
        v.visit(this);
    }

    Character::Character() 
    : Type::Type()
    {
        mKind = "character";
    }

    Character* Character::clone() {
        auto clone = new Character(*this);
        
        if (mChildren.size() > 0 && mChildren[0] != nullptr) {
            // has and array child
            auto typeChild = dynamic_cast<Array*>(mChildren[0]);

            if (typeChild != nullptr) {
                clone->setArray(typeChild->clone());
            }
        }

        return clone;
    }

    Type::Types Character::getType() {
        return Type::Types::Character;
    }

    void Character::accept(Visitor &v) {
        v.visit(this);
    }

    Void::Void() 
    : Type::Type()
    {
        mKind = "void";
    }

    Void* Void::clone() {
        auto clone = new Void(*this);
        
        if (mChildren.size() > 0 && mChildren[0] != nullptr) {
            // has and array child
            auto typeChild = dynamic_cast<Array*>(mChildren[0]);

            if (typeChild != nullptr) {
                clone->setArray(typeChild->clone());
            }
        }

        return clone;
    }

    Type::Types Void::getType() {
        return Type::Types::Void;
    }

    void Void::accept(Visitor &v) {
        v.visit(this);
    }

} // ast
