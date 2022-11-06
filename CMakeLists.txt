cmake_minimum_required(VERSION 3.23)
project(externalCode3)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE main.cpp)

include_directories(BigInt)
add_subdirectory(BigInt)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} big_int_lib)

add_subdirectory(GTESTS)
