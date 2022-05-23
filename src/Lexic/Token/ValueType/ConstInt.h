#pragma once
#include "ValueType.h"

class TokenConstInt : public ValueType {
    public:
    TokenConstInt(const uint32_t value) : ValueType(TokenType::CONST_INT), value(value) {}
    virtual const std::string to_string() const;

    const uint32_t value;
};

inline const std::string TokenConstInt::to_string() const {
    return Token::to_string() + ". Value: " + std::to_string(value);
}