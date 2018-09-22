/* custom types for the Nonsense parser. */

#include "types.hpp"

std::ostream &operator<<(std::ostream &os, Identifier const &id) { 
    return os << "ID:" << id.key << ":" << id.offset;
}

std::ostream &operator<<(std::ostream &os, Identifier const *id) { 
    return os << "ID:" << id->key << ":" << id->offset;
}

std::ostream &operator<<(std::ostream &os, Expression const &exp) { 
    return os << exp.location;
}

std::ostream &operator<<(std::ostream &os, Expression const *exp) { 
    return os << exp->location;
}

SymbolTable::SymbolTable() {
    m_next_offset = -4;
}

SymbolTable::~SymbolTable() {
    m_map.clear();
}

Identifier* SymbolTable::lookup(std::string key) {
    if (m_map.count(key) == 1) {
        // std::cerr << "Found symbol: " << m_map.at(key) << std::endl;
        return m_map.at(key);
    } else {
        return allocate(key);
    }
}

Identifier* SymbolTable::allocate(std::string key) {
    if (m_map.count(key) == 0) {
        // std::cerr << "Allocating for symbol: " << key << std::endl;
        m_map[key] = new Identifier(key, m_next_offset);
        m_next_offset -= 4;
        return m_map[key];
    } else {
        return m_map[key];
    }
}

RegisterManager::RegisterManager() {
    // all registers are free
    m_register_map["%ecx"] = true;
    m_register_map["%edx"] = true;
    m_register_map["%esi"] = true;
    m_register_map["%edi"] = true;

    m_allocated_bytes = 0;
}

std::string RegisterManager::get_free_register() {
    std::cout << "// obtaining free location... ";
    for (auto &map_pair : m_register_map) {
        if (map_pair.second == true) {
            map_pair.second = false;
            std::cout << "got " << map_pair.first << "!\n";
            return map_pair.first;
        }
    }

    // full map. allocate a spot in memory.
    m_allocated_bytes += 4;
    std::string location = "dword ptr [%ebp-" + std::to_string(64 + m_allocated_bytes) + "]";
    std::cout << "got " << location << "!\n";

    std::cout <<
        "sub %esp, 4\n"
    ;

    return location;
}

bool RegisterManager::get_eligibility(std::string location) {
    if (m_register_map.count(location) == 1) {
        return m_register_map.at(location);
    } else if (m_memory_map.count(location) == 1) {
        return m_memory_map.at(location);
    } else {
        return false;
    }
}

void RegisterManager::clear_single(std::string location) {
    std::cout << "// clearing register " << location << std::endl;
    if (m_register_map.count(location) == 1) {
        m_register_map[location] = true;
    } else if (m_memory_map.count(location) == 1) {
        m_memory_map[location] = true;
    } else {
        std::cout << "// /!\\ tried to clear a nonexistant register \n";
    }
}

void RegisterManager::clear_all() {
    std::cout << "// clearing the register manager...\n";
    for (auto &map_pair : m_register_map) {
        map_pair.second = true;
    }

    if (m_allocated_bytes > 0) {
        std::cout << "add %esp, " << m_allocated_bytes << std::endl;
        m_allocated_bytes = 0;
    }
}