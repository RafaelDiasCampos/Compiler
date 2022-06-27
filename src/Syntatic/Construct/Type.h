#pragma once

#include "Construct.h"

class Type : public Construct {
public:
    enum IdType {
        INT,
        FLOAT,
        CHAR
    };
    Type(IdType idType) : idType(idType) {}
    ~Type() {}

    static const std::list<Token::TokenType> follow;
private:
    IdType idType;
};

inline const std::list<Token::TokenType> Type::follow = {Token::ID};