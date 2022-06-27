#pragma once

#include "Construct.h"
#include "Type.h"
#include "IdentList.h"

class Decl : public Construct {
public:
    Decl(std::unique_ptr<Type> type, std::unique_ptr<IdentList> identList)  : type(std::move(type)), identList(std::move(identList)) {}
    ~Decl() {}

    static const std::list<Token::TokenType> follow;
private:
    std::unique_ptr<Type> type;
    std::unique_ptr<IdentList> identList;
};

inline const std::list<Token::TokenType> Decl::follow = {Token::SEMICOLON};