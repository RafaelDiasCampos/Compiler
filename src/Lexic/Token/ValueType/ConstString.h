#pragma once
#include "ValueType.h"

class TokenConstString : public ValueType {
    public:
    TokenConstString(const std::string value) : ValueType(TokenType::CONST_INT), value(value) {}
    const std::string value;
};