#pragma once

#include "Construct.h"

class RelOp : public Construct {
public:
    enum RelOpOperation {
        EQUALS,
        NOT_EQUALS,
        LESS_THAN,
        LESS_THAN_OR_EQUAL,
        GREATER_THAN,
        GREATER_THAN_OR_EQUAL
    };
    RelOp(RelOpOperation operation) : operation(operation) {}
    ~RelOp() {}
private:
    RelOpOperation operation;
};