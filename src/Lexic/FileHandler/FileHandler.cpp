#include "FileHandler.h"

FileHandler::FileHandler(std::string filename) {
    file = std::ifstream(filename);

    if (!file.is_open()) {
        throw "Error while oepening file";
    }
}

bool FileHandler::getNextChar(char &c) {
    file.get(last_read);

    c = last_read;
    if (file) {
        return true;
    } else {
        return false;
    }
}

void FileHandler::putback() {
    file.putback(last_read);
}