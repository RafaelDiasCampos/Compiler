#pragma once

class FactorA;

#include "Construct.h"
#include "Factor.h"

class FactorA : public Construct {
public:
    enum FactorAType {
        Base,
        Not,
        Minus
    };
    FactorA(std::unique_ptr<Factor> factor, FactorAType type) : factor(std::move(factor)), type(type) {}
    ~FactorA() {}
private:
    std::unique_ptr<Factor> factor;
    FactorAType type;
};