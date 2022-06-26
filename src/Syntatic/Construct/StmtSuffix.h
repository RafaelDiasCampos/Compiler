#pragma once

#include "Construct.h"
#include "Condition.h"

class StmtSuffix : public Construct {
public:
    StmtSuffix(std::unique_ptr<Condition> condition) : condition(std::move(condition)) {}
    ~StmtSuffix() {}
private:
    std::unique_ptr<Condition> condition;
};