#pragma once

class TermA;

#include "Construct.h"
#include "Term.h"

class TermA : public Construct {
public:
    TermA(std::unique_ptr<FactorA> factorA, std::unique_ptr<Term> term) : factorA(std::move(factorA)),
                                                                          term(std::move(term)){}
    ~TermA() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term;
};

inline const std::list<Token::TokenType> TermA::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                          Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE,
                                                          Token::SUB, Token::ADD, Token::OR };