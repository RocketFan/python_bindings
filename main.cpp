#include <iostream>
#include <pybind11_example/simple_functions.h>

int main() {
    auto x = pybind11_example::add(2, 3);
    std::cout << x << std::endl;

    return 0;
}