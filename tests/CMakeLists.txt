cmake_minimum_required(VERSION 3.20)
set(TARGET err_fusion_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECT_SOURCES *cpp)

add_executable(${TARGET} ${PROJECT_SOURCES})

target_link_libraries(${TARGET} PUBLIC gtest_main)
target_include_directories(${TARGET} PUBLIC ../include)

enable_testing()
add_test(NAME ${TARGET} COMMAND ${TARGET})
