#pragma once

class StmtList;

#include "Construct.h"

class IdentList : public Construct {
public:
    IdentList(std::list<TokenId*> identList) : identList(std::move(identList)) {}
    ~IdentList() {}

    static const std::list<Token::TokenType> follow;
private:
    std::list<TokenId*> identList;
};

inline const std::list<Token::TokenType> IdentList::follow = {Token::SEMICOLON};