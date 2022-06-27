#pragma once

class SimpleExpr;

#include "Construct.h"
#include "AddOp.h"
#include "TermA.h"

class SimpleExpr : public Construct {
public:
    SimpleExpr() {}
    SimpleExpr(std::unique_ptr<AddOp> addOp, std::unique_ptr<TermA> termA, std::unique_ptr<SimpleExpr> simpleExpr) : 
                                                                           addOp(std::move(addOp)), 
                                                                           termA(std::move(termA)),
                                                                           simpleExpr(std::move(simpleExpr)){}
    ~SimpleExpr() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<AddOp> addOp;
    std::unique_ptr<TermA> termA;
    std::unique_ptr<SimpleExpr> simpleExpr;
};

inline const std::list<Token::TokenType> SimpleExpr::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                               Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE};