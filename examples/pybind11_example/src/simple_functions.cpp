#include "pybind11_example/simple_functions.h"

#include <iostream>
#include <opencv2/highgui.hpp>

using namespace pybind11_example;

float pybind11_example::add(float a, float b) {
    // std::cout << "Result: " << std::endl;
    return a + b;
}