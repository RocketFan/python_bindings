#include "pybind11_example/observer/publisher.h"

#include <memory>
#include <iostream>

#include "pybind11_example/observer/ISubscriber.h"

using namespace pybind11_example;

void Publisher::attach(std::shared_ptr<ISubscriber> sub) {
    this->_sub_list.push_back(sub);
}

void Publisher::detach(std::shared_ptr<ISubscriber> sub) {}

void Publisher::notify(std::string message) {
    this->message = message;
    std::cout << "Ok" << std::endl;

    for(auto sub : _sub_list)
        sub->update(shared_from_this());
}