#include "astclausenode.hpp"
#include "astcaselabelsnode.hpp"
#include "aststmtnode.hpp"
#include "visitor.hpp"

namespace ast {

    Clause::Clause(CaseLabels* cl, Statement* s) {
        mKind = "clause";

        mChildren.resize(2);

        mChildren[0] = cl;
        mChildren[1] = s;

        mAsmEndLabel = "";
    }

    void Clause::accept(Visitor &v) {
        v.visit(this);
    }

    ast::CaseLabels* Clause::getLabelNode() {
        return dynamic_cast<ast::CaseLabels*>(mChildren[0]);
    }

    std::string Clause::getAsmStartLabel() {
        return mAsmStartLabel;
    }

    void Clause::setAsmStartLabel(std::string label) {
        mAsmStartLabel = label;
    }

    std::string Clause::getAsmEndLabel() {
        return mAsmEndLabel;
    }

    void Clause::setAsmEndLabel(std::string label) {
        mAsmEndLabel = label;
    }

} // ast