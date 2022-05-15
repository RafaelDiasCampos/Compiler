#pragma once
#include "ValueType.h"
#include <string>

class TokenConstFloat : public ValueType {
    public:
    TokenConstFloat(const float value) : ValueType(TokenType::CONST_FLOAT), value(value) {}
    std::string to_string();

    const float value;
};

inline std::string TokenConstFloat::to_string() {
    return Token::to_string() + ". Value: " + std::to_string(value);
}