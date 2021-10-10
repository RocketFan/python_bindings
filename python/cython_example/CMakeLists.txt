cmake_minimum_required(VERSION 3.4)
project(cython_example)

if(SKBUILD)
    find_package(PythonExtensions REQUIRED)
    find_package(Cython REQUIRED)


    add_cython_target(${PROJECT_NAME}_cython
        simple_functions.pyx
        CXX
    )

    add_library(${PROJECT_NAME} ${${PROJECT_NAME}_cython})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
    python_extension_module(${PROJECT_NAME})
    install(TARGETS ${PROJECT_NAME} DESTINATION .)
endif()