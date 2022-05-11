#pragma once
#include "ValueType.h"

class TokenConstFloat : public ValueType {
    public:
    TokenConstFloat(const float value) : ValueType(TokenType::CONST_FLOAT), value(value) {}
    const float value;
};