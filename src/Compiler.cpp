#include <iostream>
#include "Lexic/Lexic.h"

void test(std::string filename){

    LexicAnalyzer lex(filename);
    Token* tok = lex.getNextToken();
    std::cout << tok << std::endl;
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = std::string(argv[1]);
    std::cout << "Starting LexicAnalyzer with file " << filename << std::endl;
    test(filename);
    return 0;
}