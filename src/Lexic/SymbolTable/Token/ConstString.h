#pragma once
#include "Token.h"

class TokenConstString : public Token {
    public:
    TokenConstString(const std::string value) : Token(TokenType::CONST_INT), value(value) {}
    const std::string value;
};