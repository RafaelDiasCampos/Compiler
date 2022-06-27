#pragma once

#include "Construct.h"

class Constant : public Construct {
public:
    Constant(ValueType *value) : value(value) {}
    ~Constant() {}

    static const std::list<Token::TokenType> follow;
private:
    ValueType* value;
};

inline const std::list<Token::TokenType> Constant::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                             Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE,
                                                             Token::SUB, Token::ADD, Token::OR, Token::MUL, Token::DIV, Token::AND};