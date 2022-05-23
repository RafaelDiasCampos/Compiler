#pragma once
#include "ValueType.h"
#include <string>

class TokenConstFloat : public ValueType {
    public:
    TokenConstFloat(const float value) : ValueType(TokenType::CONST_FLOAT), value(value) {}
    virtual const std::string to_string() const;

    const float value;
};

inline const std::string TokenConstFloat::to_string() const {
    return Token::to_string() + ". Value: " + std::to_string(value);
}