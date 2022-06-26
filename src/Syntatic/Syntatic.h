#pragma once

#include "../Lexic/Lexic.h"
#include "../Syntatic/Construct/Basic/Program.h"

class SyntaticAnalyzer {
    public:
    SyntaticAnalyzer(std::string filename) : lexic(filename) {};
    ~SyntaticAnalyzer() {}

    Program getProgram();

    private:
    LexicAnalyzer lexic;
};