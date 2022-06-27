#pragma once

#include "Construct.h"
#include "SimpleExpr.h"

class Writable : public Construct {
public:
    Writable(TokenConstString* literal) : literal(literal) {}
    Writable(std::unique_ptr<SimpleExprA> simpleExpr) : simpleExpr(std::move(simpleExpr)) {}
    ~Writable() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<SimpleExprA> simpleExpr;
    TokenConstString* literal;
};

inline const std::list<Token::TokenType> Writable::follow = {Token::CLOSE_BRACES};