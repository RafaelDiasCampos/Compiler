#pragma once

#include "Construct.h"
#include "Expression.h"

class Condition : public Construct {
public:
    Condition(std::unique_ptr<Expression> expression) : expression(std::move(expression)) {}
    ~Condition() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Expression> expression;
};

inline const std::list<Token::TokenType> Condition::follow = {Token::END, Token::ELSE, Token::UNTIL, Token::THEN, Token::DO};