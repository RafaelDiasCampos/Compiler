#pragma once

class Factor;

#include "Construct.h"
#include "Expression.h"

class Factor : public Construct {
public:
    enum FactorType {
        Id,
        Const,
        Expr
    };
    Factor(TokenId* id) : id(id), type(Id){}
    Factor(ValueType* constant) : constant(constant), type(Const) {}
    Factor(std::unique_ptr<Expression> expr) : expr(std::move(expr)), type(Expr) {}
    ~Factor() {}
private:
    FactorType type;
    TokenId* id;
    ValueType* constant;
    std::unique_ptr<Expression> expr;
};