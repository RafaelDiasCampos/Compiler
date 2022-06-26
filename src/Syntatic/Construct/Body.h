#pragma once

#include "Construct.h"
#include "DeclList.h"
#include "StmtList.h"

class Body : public Construct {
public:
    Body(std::unique_ptr<StmtList> stmtList)  : stmtList(std::move(stmtList)) {}
    Body(std::unique_ptr<DeclList> declList, std::unique_ptr<StmtList> stmtList)  : declList(std::move(declList)), stmtList(std::move(stmtList)) {}
    ~Body() {}
private:
    std::unique_ptr<DeclList> declList;
    std::unique_ptr<StmtList> stmtList;
};