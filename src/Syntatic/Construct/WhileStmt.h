#pragma once

class WhileStmt;

#include "Construct.h"
#include "StmtList.h"

class WhileStmt : public Construct {
public:
    WhileStmt(std::unique_ptr<StmtList> stmtList) : stmtList(std::move(stmtList)) {}
    ~WhileStmt() {}
private:
    std::unique_ptr<StmtList> stmtList;
};