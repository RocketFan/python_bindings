cmake_minimum_required(VERSION 3.4)
project(python_bindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda)
find_package(OpenCV REQUIRED)

add_subdirectory(lib)
add_subdirectory(examples)
add_subdirectory(python)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC pybind11_example_lib)