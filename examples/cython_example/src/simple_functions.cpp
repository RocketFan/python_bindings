#include "cython_example/simple_functions.h"

#include <iostream>

using namespace cython_example;

float cython_example::add(float a, float b) {
    // std::cout << "Result: " << std::endl;
    return a + b;
}