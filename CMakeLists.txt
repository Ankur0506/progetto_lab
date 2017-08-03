cmake_minimum_required(VERSION 3.7)
project(progetto_lab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(progetto_lab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(progetto_lab core)