#pragma once

#include "Construct.h"
#include "Condition.h"

class StmtSuffix : public Construct {
public:
    StmtSuffix(std::unique_ptr<Condition> condition) : condition(std::move(condition)) {}
    ~StmtSuffix() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Condition> condition;
};

inline const std::list<Token::TokenType> StmtSuffix::follow = {Token::END, Token::ELSE, Token::UNTIL};