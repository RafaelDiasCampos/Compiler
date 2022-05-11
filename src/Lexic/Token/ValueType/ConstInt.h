#pragma once
#include "ValueType.h"

class TokenConstInt : public ValueType {
    public:
    TokenConstInt(const uint32_t value) : ValueType(TokenType::CONST_INT), value(value) {}
    const uint32_t value;
};