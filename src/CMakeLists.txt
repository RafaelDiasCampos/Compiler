add_subdirectory(Lexic)

add_executable(Compiler Compiler.cpp)

target_link_libraries(Compiler PRIVATE Lexic)
configure_file(Compiler.h.in Compiler.h)
