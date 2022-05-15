#pragma once
#include "Token.h"
#include "ValueType/ValueType.h"
#include <memory>

class TokenId : public Token {
    public:
    TokenId(const std::string id) : Token(TokenType::ID), id(id) {}
    std::string to_string();

    const std::string id;
    std::unique_ptr<ValueType> value;
};

inline std::string TokenId::to_string() {
    return Token::to_string() + ". Value: " + id;
}