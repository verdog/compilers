#include "registermanager.hpp"

#include <iostream>

RegisterManager::RegisterManager() {
    // all registers are free
    mRegisterMap["%ebx"] = true;
    mRegisterMap["%ecx"] = true;
    mRegisterMap["%esi"] = true;
    mRegisterMap["%edi"] = true;

    mAllocatedBytes = 0;
}

std::string RegisterManager::get_free_register() {
    for (auto &map_pair : mRegisterMap) {
        if (map_pair.second == true) {
            map_pair.second = false;
            return map_pair.first;
        }
    }

    // full map. allocate a spot in memory.
    std::cerr << "Ran out of free registers!\n";

    std::exit(-1);
    return "";
}

bool RegisterManager::get_eligibility(std::string location) {
    if (mRegisterMap.count(location) == 1) {
        return mRegisterMap.at(location);
    } else if (mMemoryMap.count(location) == 1) {
        return mMemoryMap.at(location);
    } else {
        return false;
    }
}

void RegisterManager::clear_single(std::string location) {
    if (mRegisterMap.count(location) == 1) {
        mRegisterMap[location] = true;
    } else if (mMemoryMap.count(location) == 1) {
        mMemoryMap[location] = true;
    } else {
    }
}

void RegisterManager::clear_all() {
    for (auto &map_pair : mRegisterMap) {
        map_pair.second = true;
    }

    if (mAllocatedBytes > 0) {
        mAllocatedBytes = 0;
    }
}