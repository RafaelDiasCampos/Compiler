#pragma once

#include "Construct.h"
#include "Writable.h"

class WriteStmt : public Construct {
public:
    WriteStmt(std::unique_ptr<Writable> writable) : writable(std::move(writable)) {}
    ~WriteStmt() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Writable> writable;
};

inline const std::list<Token::TokenType> WriteStmt::follow = {Token::END, Token::ELSE, Token::UNTIL};