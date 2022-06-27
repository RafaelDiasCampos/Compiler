#pragma once

#include "Construct.h"
#include "Body.h"

class Program : public Construct {
public:
    Program(std::unique_ptr<Body> body) : body(std::move(body)) {}
    ~Program() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Body> body;
};

inline const std::list<Token::TokenType> Program::follow = {Token::END};