#pragma once
#include "ValueType.h"

class TokenConstChar : public ValueType {
    public:
    TokenConstChar(const char value) : ValueType(TokenType::CONST_CHAR), value(value) {}
    virtual const std::string to_string() const;

    const char value;
};

inline const std::string TokenConstChar::to_string() const {
    return Token::to_string() + ". Value: '" + value + "'";
}