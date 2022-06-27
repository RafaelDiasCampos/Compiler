#pragma once

#include "Construct.h"
#include "Condition.h"

class StmtPrefix : public Construct {
public:
    StmtPrefix(std::unique_ptr<Condition> condition) : condition(std::move(condition)) {}
    ~StmtPrefix() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Condition> condition;
};

inline const std::list<Token::TokenType> StmtPrefix::follow = {Token::ID, Token::IF, Token::REPEAT, Token::WHILE, Token::READ, Token::WRITE};