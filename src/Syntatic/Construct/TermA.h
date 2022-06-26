#pragma once

class TermA;

#include "Construct.h"
#include "Term.h"

class TermA : public Construct {
public:
    TermA(std::unique_ptr<FactorA> factorA, std::unique_ptr<Term> term) : factorA(std::move(factorA)),
                                                                          term(std::move(term)){}
    ~TermA() {}
private:
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term;
};