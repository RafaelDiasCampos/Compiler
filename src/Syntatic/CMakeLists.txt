add_subdirectory(Contruct)

add_library(Syntatic SHARED Syntatic.cpp)
target_link_libraries(Syntatic PRIVATE Lexic)