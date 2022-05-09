#pragma once
#include "Token.h"

class TokenConstFloat : public Token {
    public:
    TokenConstFloat(const float value) : Token(TokenType::CONST_FLOAT), value(value) {}
    const float value;
};