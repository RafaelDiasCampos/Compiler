#pragma once
#include "ValueType.h"

class TokenConstString : public ValueType {
    public:
    TokenConstString(const std::string value) : ValueType(TokenType::CONST_STRING), value(value) {}
    virtual const std::string to_string() const;

    const std::string value;
};

inline const std::string TokenConstString::to_string() const {
    return Token::to_string() + ". Value: \"" + value + "\"";
}