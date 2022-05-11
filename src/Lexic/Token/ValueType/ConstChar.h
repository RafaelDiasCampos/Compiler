#pragma once
#include "ValueType.h"

class TokenConstChar : public ValueType {
    public:
    TokenConstChar(const char value) : ValueType(TokenType::CONST_CHAR), value(value) {}
    const char value;
};