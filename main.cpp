#include <iostream>
#include <pybind11_example/simple_functions.h>
#include <pybind11_example/observer/publisher.h>
#include <pybind11_example/observer/subscriber.h>

int main() {
    auto x = pybind11_example::add(2, 3);
    std::cout << x << std::endl;

    auto pub = pybind11_example::Publisher();
    auto sub = pybind11_example::Subscriber();

    pub.attach(sub);
    pub.notify("Update!!!");
    pub.notify("Update!!!");
    pub.notify("Update!!!");

    return 0;
}