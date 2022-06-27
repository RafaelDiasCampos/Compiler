#pragma once

class StmtList;

#include "Construct.h"
#include "Decl.h"

class DeclList : public Construct {
public:
    DeclList(std::list<std::unique_ptr<Decl>> declList) : declList(std::move(declList)) {}
    ~DeclList() {}

    static const std::list<Token::TokenType> follow;
private:
    std::list<std::unique_ptr<Decl>> declList;
};

inline const std::list<Token::TokenType> DeclList::follow = {Token::BEGIN};