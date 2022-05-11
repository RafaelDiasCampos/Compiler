#pragma once
#include "Token.h"

class TokenId : public Token {
    public:
    TokenId(const std::string id) : Token(TokenType::ID), id(id) {}

    const std::string id;
    std::unique_ptr<Token> value;
};