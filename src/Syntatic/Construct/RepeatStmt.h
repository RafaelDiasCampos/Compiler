#pragma once

class RepeatStmt;

#include "Construct.h"
#include "StmtList.h"
#include "StmtSuffix.h"

class RepeatStmt : public Construct {
public:
    RepeatStmt(std::unique_ptr<StmtList> stmtList, std::unique_ptr<StmtSuffix> stmtSuffix) : stmtList(std::move(stmtList)),
                                                                                             stmtSuffix(std::move(stmtSuffix)) {}
    ~RepeatStmt() {}
private:
    std::unique_ptr<StmtList> stmtList;
    std::unique_ptr<StmtSuffix> stmtSuffix;
};