cmake_minimum_required(VERSION 3.26)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(ComplexNumbers_run ${SOURCE_FILES})

include_directories(ComplexNumbers_lib)
add_subdirectory(ComplexNumbers_lib)

target_link_libraries(ComplexNumbers_run ComplexNumbers_lib)

add_subdirectory(Google_tests)
