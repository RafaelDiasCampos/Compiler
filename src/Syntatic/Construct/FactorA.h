#pragma once

class FactorA;

#include "Construct.h"
#include "Factor.h"

class FactorA : public Construct {
public:
    enum FactorAType {
        Base,
        Not,
        Sub
    };
    FactorA(std::unique_ptr<Factor> factor, FactorAType type) : factor(std::move(factor)), type(type) {}
    ~FactorA() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Factor> factor;
    FactorAType type;
};

inline const std::list<Token::TokenType> FactorA::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                            Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE,
                                                            Token::SUB, Token::ADD, Token::OR, Token::MUL, Token::DIV, Token::AND};