add_subdirectory(Lexic)
add_subdirectory(Syntatic)

add_executable(Compiler Compiler.cpp)

target_link_libraries(Compiler PRIVATE Syntatic)
target_link_libraries(Compiler PUBLIC Lexic)
configure_file(Compiler.h.in Compiler.h)
