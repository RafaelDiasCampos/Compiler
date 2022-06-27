#pragma once

class Term;

#include "Construct.h"
#include "MulOp.h"
#include "FactorA.h"

class Term : public Construct {
public:
    Term() {}
    Term(std::unique_ptr<MulOp> mulOp, std::unique_ptr<FactorA> factorA, std::unique_ptr<Term> term) : mulOp(std::move(mulOp)), 
                                                                                                       factorA(std::move(factorA)),
                                                                                                       term(std::move(term)){}
    ~Term() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<MulOp> mulOp;
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term;
};

inline const std::list<Token::TokenType> Term::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                         Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE,
                                                         Token::SUB, Token::ADD, Token::OR };