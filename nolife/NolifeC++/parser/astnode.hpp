#pragma once

#include <string>
#include <vector>

class Visitor;

namespace ast {
    
    class Base {
        public:
            Base()
            : mKind {"base"}
            {}

            virtual void accept(Visitor &v);

            std::string getKind() const;

            bool addChild(Base* node);
            std::vector<Base*>& getChildren();

        protected:
            std::string mKind;
            std::vector<Base*> mChildren;
    };

} // ast