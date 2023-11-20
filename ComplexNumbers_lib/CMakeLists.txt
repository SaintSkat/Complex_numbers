cmake_minimum_required(VERSION 3.26)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_FILES
        ComplexNumber.h
)

set(SOURCE_FILES
        ComplexNumber.cpp
)

add_library(ComplexNumbers_lib ${SOURCE_FILES} ${HEADER_FILES})

#add_library(ComplexNumbers_lib ComplexNumber.cpp)