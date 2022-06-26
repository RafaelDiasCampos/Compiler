#pragma once

class SimpleExprA;

#include "Construct.h"
#include "SimpleExpr.h"
#include "TermA.h"

class SimpleExprA : public Construct {
public:
    SimpleExprA() {}
    SimpleExprA(std::unique_ptr<TermA> term, std::unique_ptr<SimpleExpr> simpleExpr) : term(std::move(term)),
                                                                                      simpleExpr(std::move(simpleExpr)) {}
    ~SimpleExprA() {}
private:
    std::unique_ptr<SimpleExpr> simpleExpr;
    std::unique_ptr<TermA> term;
};