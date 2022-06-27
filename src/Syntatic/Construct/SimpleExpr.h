#pragma once

class SimpleExpr;

#include "Construct.h"
#include "AddOp.h"
#include "TermA.h"

class SimpleExpr : public Construct {
public:
    SimpleExpr() {}
    SimpleExpr(std::unique_ptr<AddOp> addOp, std::unique_ptr<TermA> termA, std::unique_ptr<SimpleExpr> simpleExpr) : 
                                                                           addOp(std::move(addOp)), 
                                                                           termA(std::move(termA)),
                                                                           simpleExpr(std::move(simpleExpr)){}
    ~SimpleExpr() {}
private:
    std::unique_ptr<AddOp> addOp;
    std::unique_ptr<TermA> termA;
    std::unique_ptr<SimpleExpr> simpleExpr;
};