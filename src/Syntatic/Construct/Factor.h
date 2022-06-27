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
    
    static const std::list<Token::TokenType> follow;
private:
    FactorType type;
    
    TokenId* id;
    std::unique_ptr<Constant> constant;
    std::unique_ptr<Expression> expr;
};

inline const std::list<Token::TokenType> Factor::follow = {Token::END, Token::THEN, Token::ELSE, Token::UNTIL, Token::DO, Token::CLOSE_BRACES,
                                                           Token::COMP_EQ, Token::COMP_GT, Token::COMP_GE, Token::COMP_LT, Token::COMP_LE, Token::COMP_NE,
                                                           Token::SUB, Token::ADD, Token::OR, Token::MUL, Token::DIV, Token::AND};