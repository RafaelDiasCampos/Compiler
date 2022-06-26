#pragma once

#include "Construct.h"

class AddOp : public Construct {
public:
    enum AddOpOperation {
        ADD,
        SUB,
        OR
    };
    AddOp(AddOpOperation operation) : operation(operation) {}
    ~AddOp() {}
private:
    AddOpOperation operation;
};