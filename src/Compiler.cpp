#include <iostream>
#include "Lexic/Lexic.h"

void testLexic(std::string filename){
    LexicAnalyzer lex(filename);

    for (Token* token = lex.getNextToken(); token->token_type != Token::END_OF_FILE; token = lex.getNextToken()) {
        if (token->token_type == Token::INVALID_TOKEN) {
            std::cout << "Invalid token at position " << lex.getFilePosition() << std::endl;
        }
        else {
            std::cout << *token << std::endl;
        }
    }
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    try {
        std::string filename = std::string(argv[1]);

        std::cout << "Starting LexicAnalyzer with file " << filename << std::endl;
        testLexic(filename);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }   
    
    return 0;
}