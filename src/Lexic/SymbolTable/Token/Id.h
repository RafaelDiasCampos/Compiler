#pragma once
#include "Token.h"

class TokenId : public Token {
    public:
    TokenId(std::string id) : Token(TokenType::ID), id(id) {}
    std::string id;
};