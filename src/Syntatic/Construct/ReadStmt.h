#pragma once

#include "Construct.h"

class ReadStmt : public Construct {
public:
    ReadStmt(TokenId* id) : id(id) {}
    ~ReadStmt() {}

    static const std::list<Token::TokenType> follow;
private:
    TokenId* id;
};

inline const std::list<Token::TokenType> ReadStmt::follow = {Token::END, Token::ELSE, Token::UNTIL};