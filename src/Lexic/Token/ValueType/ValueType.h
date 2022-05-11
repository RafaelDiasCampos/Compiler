#pragma once
#include "../Token.h"

class ValueType : public Token {
    public:
    ValueType(TokenType value_type) : Token(value_type) {}
};