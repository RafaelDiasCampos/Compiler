#pragma once
#include "Token.h"
#include "ValueType/ValueType.h"
#include <memory>

class TokenId : public Token {
    public:
    TokenId(const std::string id) : Token(TokenType::ID), id(id) {}
    virtual const std::string to_string() const;

    std::unique_ptr<ValueType> value;

    private:
    const std::string id;
};

inline const std::string TokenId::to_string() const {
    return Token::to_string() + ". Name: " + id;
}