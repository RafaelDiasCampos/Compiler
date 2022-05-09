add_subdirectory(Lexic)

add_executable(CompilerNAME Compiler.cpp)

target_link_libraries(CompilerNAME PRIVATE Lexic)
configure_file(Compiler.h.in Compiler.h)
