cmake_minimum_required(VERSION 3.30)
#add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=utf-8>")
project(discretka)

set(CMAKE_CXX_STANDARD 20)

add_executable(discretka main.cpp bfs.cpp dfs.cpp)

