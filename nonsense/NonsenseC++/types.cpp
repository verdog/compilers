/* custom types for the Nonsense parser. */

#include "types.hpp"

std::ostream &operator<<(std::ostream &os, Identifier const &id) { 
    return os << "ID:" << id.key << ":" << id.offset;
}

std::ostream &operator<<(std::ostream &os, Identifier const *id) { 
    return os << "ID:" << id->key << ":" << id->offset;
}

SymbolTable::SymbolTable() {
    m_next_offset = -4;
}

SymbolTable::~SymbolTable() {
    // todo: clear all elements in map.
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