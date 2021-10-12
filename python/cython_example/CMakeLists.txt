cmake_minimum_required(VERSION 3.4)
project(cython_example)

# That checks if it's build by scikit-build to not throw error for missing packages
if(SKBUILD)
    find_package(PythonExtensions REQUIRED)
    find_package(Cython REQUIRED)

    # Add C++ bind using cython to Python
    # The name of the library should be same as module name (name in PYBIND11_MODULE)
    add_cython_target(simple_functions simple_functions.pyx CXX) # That is needed to add it as library
    add_library(simple_functions MODULE ${simple_functions}) # Add C++ module library
    add_library(${PROJECT_NAME}::simple_functions ALIAS simple_functions) # Add alias to library
    target_link_libraries(simple_functions ${PROJECT_NAME}_lib) # Add some dependecie libraries
    python_extension_module(simple_functions) # Add Library as Python module
    install(TARGETS simple_functions DESTINATION python/cython_example) # Destination should be path to python package
endif()