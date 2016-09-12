cmake_minimum_required(VERSION 3.6)

add_subdirectory(src)

set(SOURCE_FILES main.cpp)
include_directories(include)
add_executable(test_matrix ${SOURCE_FILES})
target_link_libraries(test_matrix LINK_PUBLIC Testing)
