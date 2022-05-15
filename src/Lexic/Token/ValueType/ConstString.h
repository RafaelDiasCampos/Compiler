#pragma once
#include "ValueType.h"

class TokenConstString : public ValueType {
    public:
    TokenConstString(const std::string value) : ValueType(TokenType::CONST_STRING), value(value) {}
    std::string to_string();

    const std::string value;
};

inline std::string TokenConstString::to_string() {
    return Token::to_string() + ". Value: \"" + value + "\"";
}