cmake_minimum_required(VERSION 3.4)
project(pybind11_example)

if(SKBUILD)
  # Scikit-Build does not add your site-packages to the search path automatically,
  # so we need to add it _or_ the pybind11 specific directory here.
  execute_process(
    COMMAND
      "${PYTHON_EXECUTABLE}" -c
      "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE _tmp_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
  list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")
endif()

pybind11_add_module(simple_functions MODULE simple_functions_py.cpp)
add_library(${PROJECT_NAME}::simple_functions ALIAS simple_functions)
target_link_libraries(simple_functions PRIVATE pybind11_example_lib)
install(TARGETS simple_functions DESTINATION python/pybind11_example)