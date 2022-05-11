add_subdirectory(FileHandler)
add_subdirectory(SymbolTable)

add_library(Lexic SHARED Lexic.cpp)
target_link_libraries(Lexic PRIVATE FileHandler)
target_link_libraries(Lexic PRIVATE SymbolTable)