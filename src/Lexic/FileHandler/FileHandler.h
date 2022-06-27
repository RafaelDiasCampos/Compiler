#pragma once
#include <fstream>
#include <stdint.h>
#include <sstream>

struct FilePosition {
    uint16_t line_number = 1;
    uint16_t column_number = 1;
};

inline std::ostream & operator<<(std::ostream & Str, FilePosition const & v) { 
  Str << "(" << v.line_number << ", " << v.column_number << ")";
  return Str;
}

inline std::string to_string(FilePosition const& arg) {
    std::ostringstream ss;
    ss << arg;
    return std::move(ss).str();
}
class FileHandler {
    public:
    FileHandler(std::string filename);
    ~FileHandler() {}

    bool get_next_char(char &c);
    void putback();

    const FilePosition get_file_position() const;

    private:
    std::ifstream file;
    char last_read;
    FilePosition file_position;

};