#include <iostream>
#include "Lexic/FileHandler/FileHandler.h"


void test(std::string filename){

    FileHandler handler(filename);
    char c;
    while (handler.getNextChar(c)){
        std::cout << c;
        handler.putback();
    }
    std::cout << std::endl;
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string filename = std::string(argv[1]);
    test(filename);
    return 0;
}