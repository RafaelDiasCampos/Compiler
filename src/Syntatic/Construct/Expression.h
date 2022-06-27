#pragma once

class Expression;

#include "Construct.h"
#include "SimpleExprA.h"
#include "RelOp.h"

class Expression : public Construct {
public:
    Expression(std::unique_ptr<SimpleExprA> expr1) : expr1(std::move(expr1)) {}
    Expression(std::unique_ptr<SimpleExprA> expr1, std::unique_ptr<RelOp> relOp, std::unique_ptr<SimpleExprA> expr2) : expr1(std::move(expr1)),
                                                                                                                     relOp(std::move(relOp)),
                                                                                                                     expr2(std::move(expr2)) {}
    ~Expression() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<SimpleExprA> expr1;
    std::unique_ptr<RelOp> relOp;
    std::unique_ptr<SimpleExprA> expr2;
};

inline const std::list<Token::TokenType> Expression::follow = {Token::END, Token::ELSE, Token::UNTIL, Token::THEN, Token::DO, Token::CLOSE_BRACES};