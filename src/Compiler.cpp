#include <iostream>
#include "Lexic/Lexic.h"

void printToken(Token *token) {
    switch (token->token_type) {
        case Token::ID:
            std::cout << ((TokenId*)token)->to_string() << std::endl;
            break;
        case Token::CONST_CHAR:
            std::cout << ((TokenConstChar*)token)->to_string() << std::endl;
            break;
        case Token::CONST_FLOAT:
            std::cout << ((TokenConstFloat*)token)->to_string() << std::endl;
            break;
        case Token::CONST_INT:
            std::cout << ((TokenConstInt*)token)->to_string() << std::endl;
            break;
        case Token::CONST_STRING:
            std::cout << ((TokenConstString*)token)->to_string() << std::endl;
            break;
        default:
            std::cout << token->to_string() << std::endl;
            break;
    }
}

void testLexic(std::string filename){
    LexicAnalyzer lex(filename);

    for (Token* token = lex.getNextToken(); token->token_type != Token::END_OF_FILE; token = lex.getNextToken()) {
        printToken(token);
    }
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = std::string(argv[1]);

    std::cout << "Starting LexicAnalyzer with file " << filename << std::endl;
    testLexic(filename);
    
    return 0;
}