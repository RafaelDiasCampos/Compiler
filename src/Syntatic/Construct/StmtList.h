#pragma once

class StmtList;

#include "Construct.h"
#include "Stmt.h"

class StmtList : public Construct {
public:
    StmtList(std::list<std::unique_ptr<Stmt>> stmtList) : stmtList(std::move(stmtList)) {}
    ~StmtList() {}

    static const std::list<Token::TokenType> follow;
private:
    std::list<std::unique_ptr<Stmt>> stmtList;
};

inline const std::list<Token::TokenType> StmtList::follow = {Token::END, Token::ELSE, Token::UNTIL};