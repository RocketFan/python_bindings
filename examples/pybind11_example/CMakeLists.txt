cmake_minimum_required(VERSION 3.4)
project(pybind11_example)

set(HEADER_DIR include/${PROJECT_NAME})

set(HEADERS
    ${HEADER_DIR}/player.h
    ${HEADER_DIR}/simple_functions.h
    ${HEADER_DIR}/observer/IPublisher.h
    ${HEADER_DIR}/observer/ISubscriber.h
    ${HEADER_DIR}/observer/publisher.h
    ${HEADER_DIR}/observer/subscriber.h
)

set(SOURCES 
    src/player.cpp
    src/simple_functions.cpp
    src/observer/publisher.cpp
    src/observer/subscriber.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)
target_link_libraries(${PROJECT_NAME}_lib PRIVATE ${OpenCV_LIBS})

