cmake_minimum_required(VERSION 3.6)

include_directories(../include/)
set(TEST_SOURCE test.cpp)

add_library(Testing SHARED ${TEST_SOURCE})
target_include_directories(Testing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
