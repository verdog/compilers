/* custom types for the Nonsense parser. */

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

typedef unsigned int uint;

struct Identifier {
    Identifier(std::string key, int offset)
    : key {key}
    , offset {offset}
    {}

    std::string key;
    int offset;
};

class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    Identifier* lookup(std::string key);
    Identifier* allocate(std::string key);
private:
    std::unordered_map<std::string, Identifier*> m_map;
    int m_next_offset;
};

std::ostream &operator<<(std::ostream &os, Identifier const &id);
std::ostream &operator<<(std::ostream &os, Identifier const *id);