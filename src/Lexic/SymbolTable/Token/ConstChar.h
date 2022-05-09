#pragma once
#include "Token.h"

class TokenConstChar : public Token {
    public:
    TokenConstChar(const char value) : Token(TokenType::CONST_INT), value(value) {}
    const char value;
};