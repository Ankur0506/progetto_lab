cmake_minimum_required(VERSION 3.7)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TestIni.cpp)
add_executable(runIniTests ${TEST_SOURCE_FILES})
target_link_libraries(runIniTests gtest gtest_main core)