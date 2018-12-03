#pragma once

#include "astnode.hpp"

namespace ast {

    class CaseLabels;
    class Statement;

    class Clause : public Base {
        public:
            Clause(CaseLabels *cl, Statement* s);

            virtual void accept(Visitor &v);
            ast::CaseLabels* getLabelNode();
            void setAsmStartLabel(std::string label);
            std::string getAsmStartLabel();
            void setAsmEndLabel(std::string label);
            std::string getAsmEndLabel();

        private:
            std::string mAsmEndLabel;
            std::string mAsmStartLabel;
    };  

} // ast