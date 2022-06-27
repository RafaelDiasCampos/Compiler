#pragma once

class SimpleExprA;

#include "Construct.h"
#include "SimpleExpr.h"
#include "TermA.h"

class SimpleExprA : public Construct {
public:
    SimpleExprA() {}
    SimpleExprA(std::unique_ptr<TermA> term, std::unique_ptr<SimpleExpr> simpleExpr) : simpleExpr(std::move(simpleExpr)),
                                                                                      term(std::move(term)) {}
    ~SimpleExprA() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<SimpleExpr> simpleExpr;
    std::unique_ptr<TermA> term;
};

inline const std::list<Token::TokenType> SimpleExprA::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                                Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE};