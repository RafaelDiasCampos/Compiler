#pragma once
#include <string>
#include <unordered_map>
#include <memory>

#include "Token/Id.h"

typedef std::unordered_map< std::string, std::unique_ptr<Token> >::const_iterator SymbolTableIt;

class SymbolTable {
    public:
    SymbolTable();

    Token* insertSymbol(std::string id, std::unique_ptr<Token> token);
    Token* insertId(std::string id);

    private:
    std::unordered_map< std::string, std::unique_ptr<Token> > table;

};