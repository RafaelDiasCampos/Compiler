#pragma once

#include "Construct.h"
#include "SimpleExpr.h"

class AssignStmt : public Construct {
public:
    AssignStmt(TokenId* id, std::unique_ptr<SimpleExprA> simpleExprA) : id(id), simpleExprA(std::move(simpleExprA)) {}
    ~AssignStmt() {}

    static const std::list<Token::TokenType> follow;
private:
    TokenId* id;
    std::unique_ptr<SimpleExprA> simpleExprA;
};

inline const std::list<Token::TokenType> AssignStmt::follow = {Token::END, Token::ELSE, Token::UNTIL};