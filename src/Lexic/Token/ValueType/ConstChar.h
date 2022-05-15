#pragma once
#include "ValueType.h"

class TokenConstChar : public ValueType {
    public:
    TokenConstChar(const char value) : ValueType(TokenType::CONST_CHAR), value(value) {}
    std::string to_string();

    const char value;
};

inline std::string TokenConstChar::to_string() {
    return Token::to_string() + ". Value: '" + value + "'";
}