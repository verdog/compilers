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

std::ostream &operator<<(std::ostream &os, Identifier const &id);
std::ostream &operator<<(std::ostream &os, Identifier const *id);

struct Expression {
    std::string location;
};

std::ostream &operator<<(std::ostream &os, Expression const &id);
std::ostream &operator<<(std::ostream &os, Expression const *id);

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

class RegisterManager {
public:
    RegisterManager();

    std::string get_free_register();
    bool get_eligibility(std::string reg);
    void clear_single(std::string location);
    void clear_all();
private:
    std::unordered_map<std::string, bool> m_register_map;
    std::unordered_map<std::string, bool> m_memory_map;
    uint m_allocated_bytes;
};

class LoopManager {
public: LoopManager();
    std::string generate_unique_label();
private:
    uint m_next_loop_number;
};