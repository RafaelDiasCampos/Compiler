#pragma once

#include "Construct.h"
#include "Condition.h"

class StmtPrefix : public Construct {
public:
    StmtPrefix(std::unique_ptr<Condition> condition) : condition(std::move(condition)) {}
    ~StmtPrefix() {}
private:
    std::unique_ptr<Condition> condition;
};