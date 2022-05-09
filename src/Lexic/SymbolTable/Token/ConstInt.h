#pragma once
#include "Token.h"

class TokenConstInt : public Token {
    public:
    TokenConstInt(const uint32_t value) : Token(TokenType::CONST_INT), value(value) {}
    const uint32_t value;
};