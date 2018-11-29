#include "conditionallabelmanager.hpp"

ConditionalLabelManager::LabelTriple::LabelTriple(std::string t, std::string f, std::string e) {
    labelTrue = t;
    labelFalse = f;
    labelEnd = e;
}

ConditionalLabelManager::ConditionalLabelManager() {
    mNextIDNumber = 0;
}

ConditionalLabelManager::LabelTriple ConditionalLabelManager::generateLabelTriple() {
    std::string number = std::to_string(mNextIDNumber++);
    return ConditionalLabelManager::LabelTriple(
        "__L_TRUE_" + number,
        "__L_FALSE_" + number,
        "__L_DONE_" + number
    );
}