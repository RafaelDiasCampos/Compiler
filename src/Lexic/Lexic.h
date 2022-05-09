#pragma once

#include <array>

#include "FileHandler/FileHandler.h"
#include "SymbolTable/SymbolTable.h"

class LexicAnalyzer {
    public:
    LexicAnalyzer(std::string filename);
    ~LexicAnalyzer() {}

    Token* getNextToken();

    private:
    void createBasicTokens();
    void insertSpecialTokens();
    
    FileHandler handler;
    SymbolTable table;
    std::array<std::unique_ptr<Token>, Token::nTokens> tokens;
};