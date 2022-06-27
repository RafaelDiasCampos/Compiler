#include <iostream>
#include "Syntatic/Syntatic.h"

void testSyntatic(std::string filename){
    SyntaticAnalyzer synt(filename);

    std::unique_ptr<Program> program = synt.parseProgram();
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " file" << std::endl;
        return 1;
    }

    try {
        std::string filename = std::string(argv[1]);
        testSyntatic(filename);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }   
    
    return 0;
}