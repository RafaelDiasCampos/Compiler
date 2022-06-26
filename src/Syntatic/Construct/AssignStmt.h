#pragma once

#include "Construct.h"
#include "SimpleExpr.h"

class AssignStmt : public Construct {
public:
    AssignStmt(TokenId* id, std::unique_ptr<SimpleExpr> simpleExpr) : id(id), simpleExpr(std::move(simpleExpr)) {}
    ~AssignStmt() {}
private:
    TokenId* id;
    std::unique_ptr<SimpleExpr> simpleExpr;
};