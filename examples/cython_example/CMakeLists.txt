cmake_minimum_required(VERSION 3.4)
project(cython_example)

include_directories(include)

set(HEADER_DIR include/${PROJECT_NAME})

set(HEADERS
    ${HEADER_DIR}/player.h
    ${HEADER_DIR}/simple_functions.h
)

set(SOURCES 
    src/player.cpp
    src/simple_functions.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)
