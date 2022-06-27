#pragma once

class Factor;

#include "Construct.h"
#include "Constant.h"
#include "Expression.h"

class Factor : public Construct {
public:
    enum FactorType {
        Id,
        Const,
        Expr
    };
    Factor(TokenId* id) : type(Id), id(id){}
    Factor(std::unique_ptr<Constant> constant) : type(Const), constant(std::move(constant)) {}
    Factor(std::unique_ptr<Expression> expr) : type(Expr), expr(std::move(expr)) {}
    ~Factor() {}
private:
    FactorType type;
    
    TokenId* id;
    std::unique_ptr<Constant> constant;
    std::unique_ptr<Expression> expr;
};