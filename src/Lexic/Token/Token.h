#pragma once
#include <string>
#include <array>

class Token {
    public:
    enum TokenType {
        // Reserved keywords
        ROUTINE = 0,
        BEGIN,
        END,
        DECLARE,
        INT,
        FLOAT,
        CHAR,
        IF,
        THEN,
        ELSE,
        REPEAT,
        UNTIL,
        WHILE,
        DO,
        READ,
        WRITE,
        NOT,
        OR,
        AND,

        // Operators
        ASSIGN,
        ADD,
        SUB,
        MUL,
        DIV,
        COMP_EQ,
        COMP_NE,
        COMP_GT,
        COMP_GE,
        COMP_LT,
        COMP_LE,

        // Special
        OPEN_BRACES,
        CLOSE_BRACES,
        SEMICOLON,
        COMMA,

        // Constants
        CONST_INT,
        CONST_FLOAT,
        CONST_CHAR,
        CONST_STRING,

        // Id
        ID,

        // Others
        END_OF_FILE,
        INVALID_TOKEN,
        ERROR,

        // End of tokens
        TOKENS_END
    };
    
    Token(const TokenType token_type) : token_type(token_type) {}
    virtual const std::string to_string() const;

    static const uint16_t n_tokens = TokenType::TOKENS_END;

    const TokenType token_type;
};

inline std::ostream & operator<<(std::ostream & Str, Token const & v) { 
  Str << v.to_string();
  return Str;
}

inline const std::string Token::to_string() const {
    std::array<std::string, Token::n_tokens> token_type_to_name;
    
    token_type_to_name[Token::ROUTINE] = "routine";
    token_type_to_name[Token::BEGIN] = "begin";
    token_type_to_name[Token::END] = "end";
    token_type_to_name[Token::DECLARE] = "declare";
    token_type_to_name[Token::INT] = "int";
    token_type_to_name[Token::FLOAT] = "float";
    token_type_to_name[Token::CHAR] = "char";
    token_type_to_name[Token::IF] = "if";
    token_type_to_name[Token::THEN] = "then";
    token_type_to_name[Token::ELSE] = "else";
    token_type_to_name[Token::REPEAT] = "repeat";
    token_type_to_name[Token::UNTIL] = "until";
    token_type_to_name[Token::WHILE] = "while";
    token_type_to_name[Token::DO] = "do";
    token_type_to_name[Token::READ] = "read";
    token_type_to_name[Token::WRITE] = "write";
    token_type_to_name[Token::NOT] = "not";
    token_type_to_name[Token::OR] = "or";;
    token_type_to_name[Token::AND] = "and";

    token_type_to_name[Token::ASSIGN] = ":=";
    token_type_to_name[Token::ADD] = "+";
    token_type_to_name[Token::SUB] = "-";
    token_type_to_name[Token::MUL] = "*";
    token_type_to_name[Token::DIV] = "/";
    token_type_to_name[Token::COMP_EQ] = "=";
    token_type_to_name[Token::COMP_NE] = "<>";
    token_type_to_name[Token::COMP_GT] = ">";
    token_type_to_name[Token::COMP_GE] = ">=";
    token_type_to_name[Token::COMP_LT] = "<";
    token_type_to_name[Token::COMP_LE] = "<=";

    token_type_to_name[Token::OPEN_BRACES] = "(";
    token_type_to_name[Token::CLOSE_BRACES] = ")";
    token_type_to_name[Token::SEMICOLON] = ";";
    token_type_to_name[Token::COMMA] = ",";

    token_type_to_name[Token::CONST_INT] = "const int";
    token_type_to_name[Token::CONST_FLOAT] = "const float";
    token_type_to_name[Token::CONST_CHAR] = "const char";
    token_type_to_name[Token::CONST_STRING] = "const string";

    token_type_to_name[Token::END_OF_FILE] = "EOF";
    token_type_to_name[Token::INVALID_TOKEN] = "invalid token";
    token_type_to_name[Token::ERROR] = "error";

    token_type_to_name[Token::ID] = "id";  

    return "Token " + token_type_to_name[token_type];
}