#pragma once

#include "Construct.h"

class AddOp : public Construct {
public:
    enum AddOpOperation {
        ADD,
        SUB,
        OR
    };
    AddOp(AddOpOperation operation) : operation(operation) {}
    ~AddOp() {}

    static const std::list<Token::TokenType> follow;
private:
    AddOpOperation operation;
};

inline const std::list<Token::TokenType> AddOp::follow = {Token::ID, Token::OPEN_BRACES, Token::NOT, Token::SUB, Token::CONST_INT, Token::CONST_FLOAT, Token::CONST_CHAR};