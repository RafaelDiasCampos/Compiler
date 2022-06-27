#include "SymbolTable.h"

SymbolTable::SymbolTable() {

}

Token*  SymbolTable::insert_symbol(std::string id, std::unique_ptr<Token> token) {
    std::pair<SymbolTableIt, bool> result = table.insert({id, std::move(token)});

    Token* tokenInserted = result.first->second.get();

    return tokenInserted;
}

Token* SymbolTable::insert_id(std::string id) {
    std::unique_ptr<Token> token = std::make_unique<TokenId>(TokenId(id));

    Token* tokenInserted = insert_symbol(id, std::move(token));

    return tokenInserted;
}