#include "Lexic.h"

LexicAnalyzer::LexicAnalyzer(std::string filename) : handler(filename) {
     createBasicTokens();
}

void LexicAnalyzer::createBasicTokens() {
    basic_tokens[Token::ROUTINE] = std::make_unique<Token>(Token::ROUTINE);
    basic_tokens[Token::BEGIN] = std::make_unique<Token>(Token::BEGIN);
    basic_tokens[Token::END] = std::make_unique<Token>(Token::END);
    basic_tokens[Token::DECLARE] = std::make_unique<Token>(Token::DECLARE);
    basic_tokens[Token::INT] = std::make_unique<Token>(Token::INT);
    basic_tokens[Token::FLOAT] = std::make_unique<Token>(Token::FLOAT);
    basic_tokens[Token::CHAR] = std::make_unique<Token>(Token::CHAR);
    basic_tokens[Token::IF] = std::make_unique<Token>(Token::IF);
    basic_tokens[Token::THEN] = std::make_unique<Token>(Token::THEN);
    basic_tokens[Token::ELSE] = std::make_unique<Token>(Token::ELSE);
    basic_tokens[Token::REPEAT] = std::make_unique<Token>(Token::REPEAT);
    basic_tokens[Token::UNTIL] = std::make_unique<Token>(Token::UNTIL);
    basic_tokens[Token::WHILE] = std::make_unique<Token>(Token::WHILE);
    basic_tokens[Token::DO] = std::make_unique<Token>(Token::DO);
    basic_tokens[Token::READ] = std::make_unique<Token>(Token::READ);
    basic_tokens[Token::WRITE] = std::make_unique<Token>(Token::WRITE);
    basic_tokens[Token::NOT] = std::make_unique<Token>(Token::NOT);
    basic_tokens[Token::OR] = std::make_unique<Token>(Token::OR);;
    basic_tokens[Token::AND] = std::make_unique<Token>(Token::AND);

    basic_tokens[Token::ASSIGN] = std::make_unique<Token>(Token::ASSIGN);
    basic_tokens[Token::ADD] = std::make_unique<Token>(Token::ADD);
    basic_tokens[Token::SUB] = std::make_unique<Token>(Token::SUB);
    basic_tokens[Token::MUL] = std::make_unique<Token>(Token::MUL);
    basic_tokens[Token::DIV] = std::make_unique<Token>(Token::DIV);
    basic_tokens[Token::COMP_EQ] = std::make_unique<Token>(Token::COMP_EQ);
    basic_tokens[Token::COMP_NE] = std::make_unique<Token>(Token::COMP_NE);
    basic_tokens[Token::COMP_GT] = std::make_unique<Token>(Token::COMP_GT);
    basic_tokens[Token::COMP_GE] = std::make_unique<Token>(Token::COMP_GE);
    basic_tokens[Token::COMP_LT] = std::make_unique<Token>(Token::COMP_LT);
    basic_tokens[Token::COMP_LE] = std::make_unique<Token>(Token::COMP_LE);

    basic_tokens[Token::OPEN_BRACES] = std::make_unique<Token>(Token::OPEN_BRACES);
    basic_tokens[Token::CLOSE_BRACES] = std::make_unique<Token>(Token::CLOSE_BRACES);

    basic_tokens[Token::CONST_INT] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_FLOAT] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_CHAR] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_STRING] = std::make_unique<Token>(Token::ERROR);

    basic_tokens[Token::END_OF_FILE] = std::make_unique<Token>(Token::END_OF_FILE);
    basic_tokens[Token::INVALID_TOKEN] = std::make_unique<Token>(Token::INVALID_TOKEN);
    basic_tokens[Token::ERROR] = std::make_unique<Token>(Token::ERROR);

    basic_tokens[Token::ID] = std::make_unique<Token>(Token::ERROR); 
}

Token* LexicAnalyzer::getNextToken() {
    return basic_tokens[Token::IF].get();
}