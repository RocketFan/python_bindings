#include "pybind11_example/observer/subscriber.h"

#include <iostream>

#include "pybind11_example/observer/publisher.h"

using namespace pybind11_example;

void Subscriber::update(std::shared_ptr<IPublisher> pub) {
    std::cout << pub->message << std::endl;
}