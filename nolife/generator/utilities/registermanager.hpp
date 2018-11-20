#pragma once

#include <string>
#include <unordered_map>

class RegisterManager {
    public:
        RegisterManager();

        std::string get_free_register();
        bool get_eligibility(std::string reg);
        void clear_single(std::string location);
        void clear_all();
    private:
        std::unordered_map<std::string, bool> mRegisterMap;
        std::unordered_map<std::string, bool> mMemoryMap;
        uint mAllocatedBytes;
};