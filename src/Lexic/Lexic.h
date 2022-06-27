#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include "FileHandler/FileHandler.h"
#include "SymbolTable/SymbolTable.h"

#include "Token/Id.h"
#include "Token/ValueType/ValueType.h"
#include "Token/ValueType/ConstChar.h"
#include "Token/ValueType/ConstFloat.h"
#include "Token/ValueType/ConstInt.h"
#include "Token/ValueType/ConstString.h"

class LexicAnalyzer {
    public:
    LexicAnalyzer(std::string filename);
    ~LexicAnalyzer() {}

    Token* get_next_token();

    const FilePosition get_file_position() const;

    const std::string to_string() const;

    private:
    void create_basic_tokens();
    void initializeSymbolTable();

    Token* parse_numeric_const();
    Token* parse_string_const();
    Token* parse_identifier();
    
    FileHandler handler;
    SymbolTable table;
    std::array< std::unique_ptr<Token>, Token::n_tokens > basic_tokens;
    std::vector< std::unique_ptr<ValueType> > value_tokens;

};

inline std::ostream & operator<<(std::ostream & Str, LexicAnalyzer const & v) { 
  Str << v.to_string();
  return Str;
}