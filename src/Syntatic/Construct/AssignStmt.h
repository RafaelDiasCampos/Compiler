#pragma once

#include "Construct.h"
#include "SimpleExpr.h"

class AssignStmt : public Construct {
public:
    AssignStmt(TokenId* id, std::unique_ptr<SimpleExprA> simpleExprA) : id(id), simpleExprA(std::move(simpleExprA)) {}
    ~AssignStmt() {}
private:
    TokenId* id;
    std::unique_ptr<SimpleExprA> simpleExprA;
};