#pragma once

#include "Construct.h"

class MulOp : public Construct {
public:
    enum MulOpOperation {
        MUL,
        DIV,
        AND
    };
    MulOp(MulOpOperation operation) : operation(operation) {}
    ~MulOp() {}
private:
    MulOpOperation operation;
};