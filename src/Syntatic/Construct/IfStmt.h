#pragma once

class IfStmt;

#include "Construct.h"
#include "Condition.h"
#include "StmtList.h"

class IfStmt : public Construct {
public:
    IfStmt(std::unique_ptr<Condition> condition, std::unique_ptr<StmtList> stmtListThen) : condition(std::move(condition)), 
                                                                                           stmtListThen(std::move(stmtListThen)) {}
    IfStmt(std::unique_ptr<Condition> condition, std::unique_ptr<StmtList> stmtListThen, std::unique_ptr<StmtList> stmtListElse) :
                                                                                           condition(std::move(condition)), 
                                                                                           stmtListThen(std::move(stmtListThen)),
                                                                                           stmtListElse(std::move(stmtListElse)) {}
    ~IfStmt() {}
private:
    std::unique_ptr<Condition> condition;
    std::unique_ptr<StmtList> stmtListThen;
    std::unique_ptr<StmtList> stmtListElse;
};