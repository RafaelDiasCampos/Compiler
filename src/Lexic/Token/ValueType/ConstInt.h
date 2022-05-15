#pragma once
#include "ValueType.h"

class TokenConstInt : public ValueType {
    public:
    TokenConstInt(const uint32_t value) : ValueType(TokenType::CONST_INT), value(value) {}
    std::string to_string();

    const uint32_t value;
};

inline std::string TokenConstInt::to_string() {
    return Token::to_string() + ". Value: " + std::to_string(value);
}