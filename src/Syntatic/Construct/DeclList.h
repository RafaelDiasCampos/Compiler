#pragma once

class StmtList;

#include "Construct.h"
#include "Decl.h"

class DeclList : public Construct {
public:
    DeclList(std::list<std::unique_ptr<Decl>> declList) : declList(std::move(declList)) {}
    ~DeclList() {}
private:
    std::list<std::unique_ptr<Decl>> declList;
};