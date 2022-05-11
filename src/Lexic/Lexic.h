#pragma once

#include <array>
#include <vector>

#include "FileHandler/FileHandler.h"
#include "SymbolTable/SymbolTable.h"

#include "Token/Id.h"
#include "Token/ValueType/ValueType.h"

class LexicAnalyzer {
    public:
    LexicAnalyzer(std::string filename);
    ~LexicAnalyzer() {}

    Token* getNextToken();

    private:
    void createBasicTokens();
    
    FileHandler handler;
    SymbolTable table;
    std::array< std::unique_ptr<Token>, Token::n_tokens > basic_tokens;
    std::vector< std::unique_ptr<Token> > value_tokens;

};