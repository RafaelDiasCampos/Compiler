add_subdirectory(FileHandler)

add_library(Lexic SHARED Lexic.cpp)
target_link_libraries(Lexic PRIVATE FileHandler)