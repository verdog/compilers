#include "caselabelmanager.hpp"

CaseLabelManager::CaseLabelManager() {
    mNextIDNumber = -1;
    mNextSubIDNumber = 0;
}

std::string CaseLabelManager::generateLabel() {
    std::string number = std::to_string(mNextIDNumber) + "_" + std::to_string(mNextSubIDNumber++);
    return "__L_CASEJMP_" + number;
}

void CaseLabelManager::newCase() {
    mNextIDNumber++;
    mNextSubIDNumber = 0;
}

std::string CaseLabelManager::getEnd() {
    return "__L_CASEEND_" + std::to_string(mNextIDNumber);
}