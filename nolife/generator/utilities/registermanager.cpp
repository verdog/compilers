#include "registermanager.hpp"

#include <iostream>
#include <regex>

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
            std::cout << "Granted " << map_pair.first << "!\n";
            return map_pair.first;
        }
    }

    // full map. allocate a spot in memory.
    std::cerr << "!!! Ran out of free registers!\n";

    return "!!! Ran out of free registers !!!";
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

    std::smatch match;
    if (std::regex_match(location, match, std::regex("\\[ %.{3} \\]"))) {
        std::regex_search(location, match, std::regex("%.{3}"));
        location = match.str(0);
    }
    
    std::cout << "Cleared " << location << "!\n";

    if (mRegisterMap.count(location) == 1) {
        mRegisterMap[location] = true;
    } else if (mMemoryMap.count(location) == 1) {
        mMemoryMap[location] = true;
    } else {
    }
}

void RegisterManager::clear_all() {
    std::cout << "Cleared all registers!\n";

    for (auto &map_pair : mRegisterMap) {
        map_pair.second = true;
    }

    if (mAllocatedBytes > 0) {
        mAllocatedBytes = 0;
    }
}

std::vector<std::string> RegisterManager::get_all_free_registers() {
    std::vector<std::string> free_regs;
    for (auto pair : mRegisterMap) {
        if (get_eligibility(pair.first)) {
            free_regs.push_back(pair.first);
        }
    }
    return free_regs;
}