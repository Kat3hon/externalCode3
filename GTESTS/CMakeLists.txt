cmake_minimum_required(VERSION 3.23)
# 'Google_test' is the subproject name
project(Google_tests)

set(CMAKE_CXX_STANDARD 20)
# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests

#add_compile_definitions(dynamic)
add_executable(Google_Tests_run ../BigInt/BigInt.cpp ../PN/PN.cpp ../dialog.cpp ../help.cpp main.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)

include_directories("../BigInt")