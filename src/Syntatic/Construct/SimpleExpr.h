#pragma once

class SimpleExpr;

#include "Construct.h"
#include "AddOp.h"
#include "TermA.h"

class SimpleExpr : public Construct {
public:
    SimpleExpr() {}
    SimpleExpr(std::unique_ptr<AddOp> addOp, std::unique_ptr<TermA> term) : addOp(std::move(addOp)), 
                                                                           term(std::move(term)){}
    ~SimpleExpr() {}
private:
    std::unique_ptr<AddOp> addOp;
    std::unique_ptr<TermA> term;
};