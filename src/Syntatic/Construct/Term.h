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
private:
    std::unique_ptr<MulOp> mulOp;
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term;
};