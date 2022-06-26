#pragma once

#include "Construct.h"

class Constant : public Construct {
public:
    Constant(ValueType *value) : value(value) {}
    ~Constant() {}
private:
    ValueType* value;
};