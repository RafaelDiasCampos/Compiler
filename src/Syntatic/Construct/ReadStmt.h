#pragma once

#include "Construct.h"

class ReadStmt : public Construct {
public:
    ReadStmt(TokenId* id) : id(id) {}
    ~ReadStmt() {}
private:
    TokenId* id;
};