#pragma once

#include <memory>
class StmtList;

#include "Construct.h"

class IdentList : public Construct {
public:
    IdentList(std::list<TokenId*> identList) : identList(std::move(identList)) {}
    ~IdentList() {}

    inline void set_type(Token::TokenType type) {
        for (auto& ident : identList) {
            if (type == Token::TokenType::CONST_INT) {
                ident->value = std::make_unique<TokenConstInt>(0);
            } else if (type == Token::TokenType::CONST_FLOAT) {
                ident->value = std::make_unique<TokenConstFloat>(0.0);
            } else if (type == Token::TokenType::CONST_CHAR) {
                ident->value = std::make_unique<TokenConstChar>('\0');
            } else {
                throw std::runtime_error("Invalid type");
            }
            ident->declared = true;
        }
    }

    static const std::list<Token::TokenType> follow;
private:
    std::list<TokenId*> identList;
};

inline const std::list<Token::TokenType> IdentList::follow = {Token::SEMICOLON};