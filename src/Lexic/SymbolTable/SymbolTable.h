#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>

#include "../Token/Id.h"

typedef std::unordered_map< std::string, std::unique_ptr<Token> >::const_iterator SymbolTableIt;

class SymbolTable {
    public:
    SymbolTable();

    Token* insert_symbol(std::string id, std::unique_ptr<Token> token);
    Token* insert_id(std::string id);

    const std::string to_string() const;

    private:
    std::unordered_map< std::string, std::unique_ptr<Token> > table;

};

inline const std::string SymbolTable::to_string() const {
    std::ostringstream ss;
    ss << "SymbolTable: " << std::endl;
    for (SymbolTableIt it = table.begin(); it != table.end(); ++it) {
        ss << it->first << ": " << it->second->to_string() << std::endl;
    }

    return std::move(ss).str();
}

inline std::ostream & operator<<(std::ostream & Str, SymbolTable const & v) {
    Str << v.to_string();
    return Str;
}