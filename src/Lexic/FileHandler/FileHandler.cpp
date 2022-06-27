#include "FileHandler.h"
#include <stdint.h>

FileHandler::FileHandler(std::string filename) {
    file = std::ifstream(filename);

    if (!file.is_open()) {
        throw "Error while oepening file";
    }
}

bool FileHandler::get_next_char(char &c) {
    file.get(last_read);

    c = last_read;
    if (file) {
        file_position.column_number++;
        if (c == '\n') {
            file_position.line_number++;
            file_position.column_number = 1;
        }
        return true;
    } else {
        return false;
    }
}

void FileHandler::putback() {
    file.putback(last_read);
    file_position.column_number--;
    if (last_read == '\n') {
        file_position.line_number--;
    }
}

const FilePosition FileHandler::get_file_position() const {
    return file_position;
}