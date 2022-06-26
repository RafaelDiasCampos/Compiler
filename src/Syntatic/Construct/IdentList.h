#pragma once

class StmtList;

#include "Construct.h"

class IdentList : public Construct {
public:
    IdentList(std::list<std::unique_ptr<TokenId>> identList) : identList(std::move(identList)) {}
    ~IdentList() {}
private:
    std::list<std::unique_ptr<TokenId>> identList;
};