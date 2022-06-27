#pragma once

#include "Construct.h"

class MulOp : public Construct {
public:
    enum MulOpOperation {
        MUL,
        DIV,
        AND
    };
    MulOp(MulOpOperation operation) : operation(operation) {}
    ~MulOp() {}

    static const std::list<Token::TokenType> follow;
private:
    MulOpOperation operation;
};

inline const std::list<Token::TokenType> MulOp::follow = {Token::ID, Token::OPEN_BRACES, Token::NOT, Token::SUB, Token::CONST_INT, Token::CONST_FLOAT, Token::CONST_CHAR};