#pragma once

class Token {
    public:
    enum TokenType {
        NUM_CONST = 0,
        ASSIGN,
        COMP_EQ,
        COMP_GT,
        COMP_LT,
        COMP_GE,
        COMP_LE,
        SEMICOLON,
        END,
        ID
    };
    
    Token(enum TokenType token_type) : token_type(token_type) {}    

    static const int nTokens = TokenType::END;

    TokenType token_type;

};