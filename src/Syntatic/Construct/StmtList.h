#pragma once

class StmtList;

#include "Construct.h"
#include "Stmt.h"

class StmtList : public Construct {
public:
    StmtList(std::list<std::unique_ptr<Stmt>> stmtList) : stmtList(std::move(stmtList)) {}
    ~StmtList() {}
private:
    std::list<std::unique_ptr<Stmt>> stmtList;
};