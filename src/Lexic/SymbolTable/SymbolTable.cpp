#include "SymbolTable.h"

SymbolTable::SymbolTable() {

}

Token*  SymbolTable::insertSymbol(std::string id, std::unique_ptr<Token> token) {
    std::pair<SymbolTableIt, bool> result = table.insert({id, std::move(token)});

    Token* tokenInserted = result.first->second.get();

    return tokenInserted;
}

Token* SymbolTable::insertId(std::string id) {
    std::unique_ptr<Token> token = std::make_unique<TokenId>(TokenId(id));

    Token* tokenInserted = insertSymbol(id, std::move(token));

    return tokenInserted;
}