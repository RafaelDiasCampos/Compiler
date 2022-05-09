#pragma once
#include <fstream>

class FileHandler {
    public:
    FileHandler(std::string filename);
    ~FileHandler() {}

    bool getNextChar(char &c);
    void putback();

    private:
    std::ifstream file;
    char last_read;

};