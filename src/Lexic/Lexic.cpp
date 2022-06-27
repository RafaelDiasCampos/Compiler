#include "Lexic.h"
#include <memory>

LexicAnalyzer::LexicAnalyzer(std::string filename) : handler(filename) {
     create_basic_tokens();
     initializeSymbolTable();
}

const FilePosition LexicAnalyzer::get_file_position() const {
    return handler.get_file_position();
}

void LexicAnalyzer::create_basic_tokens() {
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
    basic_tokens[Token::SEMICOLON] = std::make_unique<Token>(Token::SEMICOLON);
    basic_tokens[Token::COMMA] = std::make_unique<Token>(Token::COMMA);

    basic_tokens[Token::CONST_INT] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_FLOAT] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_CHAR] = std::make_unique<Token>(Token::ERROR);
    basic_tokens[Token::CONST_STRING] = std::make_unique<Token>(Token::ERROR);

    basic_tokens[Token::END_OF_FILE] = std::make_unique<Token>(Token::END_OF_FILE);
    basic_tokens[Token::INVALID_TOKEN] = std::make_unique<Token>(Token::INVALID_TOKEN);
    basic_tokens[Token::ERROR] = std::make_unique<Token>(Token::ERROR);

    basic_tokens[Token::ID] = std::make_unique<Token>(Token::ERROR); 
}

void LexicAnalyzer::initializeSymbolTable () {
    table.insert_symbol("routine", std::make_unique<Token>(Token::ROUTINE));
    table.insert_symbol("begin", std::make_unique<Token>(Token::BEGIN));
    table.insert_symbol("end", std::make_unique<Token>(Token::END));
    table.insert_symbol("declare", std::make_unique<Token>(Token::DECLARE));
    table.insert_symbol("int", std::make_unique<Token>(Token::INT));
    table.insert_symbol("float", std::make_unique<Token>(Token::FLOAT));
    table.insert_symbol("char", std::make_unique<Token>(Token::CHAR));
    table.insert_symbol("if", std::make_unique<Token>(Token::IF));
    table.insert_symbol("then", std::make_unique<Token>(Token::THEN));
    table.insert_symbol("else", std::make_unique<Token>(Token::ELSE));
    table.insert_symbol("repeat", std::make_unique<Token>(Token::REPEAT));
    table.insert_symbol("until", std::make_unique<Token>(Token::UNTIL));
    table.insert_symbol("while", std::make_unique<Token>(Token::WHILE));
    table.insert_symbol("do", std::make_unique<Token>(Token::DO));
    table.insert_symbol("read", std::make_unique<Token>(Token::READ));
    table.insert_symbol("write", std::make_unique<Token>(Token::WRITE));
    table.insert_symbol("not", std::make_unique<Token>(Token::NOT));
    table.insert_symbol("or", std::make_unique<Token>(Token::OR));
    table.insert_symbol("and", std::make_unique<Token>(Token::AND));
}

Token* LexicAnalyzer::get_next_token() {
    char c;
    while (handler.get_next_char(c)) {
        switch (c) {
            case ' ':
            case '\n':
            case '\t': continue;

            case '%': while (handler.get_next_char(c) && c != '%') {}
                if (c == '%') {
                    continue;
                }
                return basic_tokens[Token::INVALID_TOKEN].get();


            case '(': return basic_tokens[Token::OPEN_BRACES].get();
            case ')': return basic_tokens[Token::CLOSE_BRACES].get();
            case ';': return basic_tokens[Token::SEMICOLON].get();
            case ',': return basic_tokens[Token::COMMA].get();
            case '+': return basic_tokens[Token::ADD].get();
            case '-': return basic_tokens[Token::SUB].get();
            case '*': return basic_tokens[Token::MUL].get();
            case '/': return basic_tokens[Token::DIV].get();
            case '=': return basic_tokens[Token::COMP_EQ].get();
            case '>': handler.get_next_char(c);
                if (c == '=') return basic_tokens[Token::COMP_GE].get();
                else {handler.putback(); return basic_tokens[Token::COMP_GT].get();}
            case '<': handler.get_next_char(c);
                if (c == '=') return basic_tokens[Token::COMP_LE].get();
                else if (c == '>') return basic_tokens[Token::COMP_NE].get();
                else {handler.putback(); return basic_tokens[Token::COMP_LT].get();}
            case ':': handler.get_next_char(c);
                if (c == '=') return basic_tokens[Token::ASSIGN].get();
                else {handler.putback(); return basic_tokens[Token::INVALID_TOKEN].get();}


            case '\'': char char_value; handler.get_next_char(char_value);
                if (handler.get_next_char(c) && c == '\'') {
                    value_tokens.insert(value_tokens.end(), std::make_unique<TokenConstChar>(char_value));
                    return value_tokens.back().get();
                }
                else {
                    handler.putback();
                    return basic_tokens[Token::INVALID_TOKEN].get();
                }
            case '"': return parse_string_const();
        }

        if (std::isdigit(c)) {
            handler.putback(); 
            return parse_numeric_const();
        }

        if (std::isalpha(c)) {
            handler.putback();
            return parse_identifier();
        }

        return basic_tokens[Token::INVALID_TOKEN].get();
    }

    return basic_tokens[Token::END_OF_FILE].get();
}

Token* LexicAnalyzer::parse_numeric_const() {
    uint32_t integer_part = 0;

    char c;
    while (handler.get_next_char(c)) {
        if (std::isdigit(c)) {
            integer_part = integer_part * 10 + (c - '0');
        } else {
            handler.putback();
            break;
        }
    }

    if (c == '.') {
        handler.get_next_char(c); // Flushes the '.' read
        uint32_t float_part = 0;
        uint32_t power = 1;

        while (handler.get_next_char(c)) {
            if (std::isdigit(c)) {
                float_part = float_part * 10 + (c - '0');
                power *= 10;
            } else {
                handler.putback();
                break;
            }
        }

        // Missing digits after the '.'
        if (power == 1) {
            return basic_tokens[Token::INVALID_TOKEN].get();
        }

        double float_value = integer_part + ((double) float_part / power);

        value_tokens.insert(value_tokens.end(), std::make_unique<TokenConstFloat>(float_value));
        return value_tokens.back().get();
    }
    
    value_tokens.insert(value_tokens.end(), std::make_unique<TokenConstInt>(integer_part));
    return value_tokens.back().get();
}

Token* LexicAnalyzer::parse_string_const() {
    std::string string_value;

    char c;
    while (handler.get_next_char(c) && c != '"') {
        string_value += c;
    }
    
    value_tokens.insert(value_tokens.end(), std::make_unique<TokenConstString>(string_value));
    return value_tokens.back().get();
}

Token* LexicAnalyzer::parse_identifier() {
    std::string id;
    char c;

    while (handler.get_next_char(c)) {
        if (std::isalnum(c)) {
            id += c;
        } else {
            handler.putback();
            break;
        }
    }

    return table.insert_id(id);
}

const std::string LexicAnalyzer::to_string() const {
    std::stringstream ss;
    ss << "LexicAnalyzer: " << std::endl;
    ss << table.to_string();
    return ss.str();
}