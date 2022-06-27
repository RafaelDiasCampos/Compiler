#pragma once

#include "Construct.h"

class RelOp : public Construct {
public:
    enum RelOpOperation {
        EQUALS,
        NOT_EQUALS,
        LESS_THAN,
        LESS_THAN_OR_EQUAL,
        GREATER_THAN,
        GREATER_THAN_OR_EQUAL
    };
    RelOp(RelOpOperation operation) : operation(operation) {}
    ~RelOp() {}

    static const std::list<Token::TokenType> follow;
private:
    RelOpOperation operation;
};

inline const std::list<Token::TokenType> RelOp::follow = {Token::ID, Token::OPEN_BRACES, Token::NOT, Token::SUB, Token::CONST_INT, Token::CONST_FLOAT, Token::CONST_CHAR};