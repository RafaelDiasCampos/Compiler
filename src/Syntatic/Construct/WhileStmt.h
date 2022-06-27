#pragma once

class WhileStmt;

#include "Construct.h"
#include "StmtList.h"
#include "StmtPrefix.h"

class WhileStmt : public Construct {
public:
    WhileStmt(std::unique_ptr<StmtPrefix> stmtPrefix, std::unique_ptr<StmtList> stmtList) : stmtPrefix(std::move(stmtPrefix)), 
                                                                                            stmtList(std::move(stmtList)) {}
    ~WhileStmt() {}
private:
    std::unique_ptr<StmtPrefix> stmtPrefix;
    std::unique_ptr<StmtList> stmtList;
};