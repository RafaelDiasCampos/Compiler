#pragma once

#include "Construct.h"
#include "SimpleExpr.h"

class Writable : public Construct {
public:
    Writable(TokenConstString* literal) : literal(literal) {}
    Writable(std::unique_ptr<SimpleExprA> simpleExpr) : simpleExpr(std::move(simpleExpr)) {}
    ~Writable() {}
private:
    std::unique_ptr<SimpleExprA> simpleExpr;
    TokenConstString* literal;
};