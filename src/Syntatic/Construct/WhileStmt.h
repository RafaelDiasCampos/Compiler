#pragma once

class WhileStmt;

#include "Construct.h"
#include "StmtList.h"
#include "StmtPrefix.h"

class WhileStmt : public Construct {
public:
    WhileStmt(std::unique_ptr<StmtPrefix> stmtPrefix, std::unique_ptr<StmtList> stmtList) : stmtPrefix(std::move(stmtPrefix)), 
                                                                                            stmtList(std::move(stmtList)) {}
    ~WhileStmt() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<StmtPrefix> stmtPrefix;
    std::unique_ptr<StmtList> stmtList;
};

inline const std::list<Token::TokenType> WhileStmt::follow = {Token::END, Token::ELSE, Token::UNTIL};