#pragma once

#include "Construct.h"
#include "Expression.h"

class Condition : public Construct {
public:
    Condition(std::unique_ptr<Expression> expression) : expression(std::move(expression)) {}
    ~Condition() {}
private:
    std::unique_ptr<Expression> expression;
};