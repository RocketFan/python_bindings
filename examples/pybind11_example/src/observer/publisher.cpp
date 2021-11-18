#include "pybind11_example/observer/publisher.h"

#include "pybind11_example/observer/ISubscriber.h"

using namespace pybind11_example;

void Publisher::attach(ISubscriber &sub) {
    this->_sub_list.push_back(&sub);
}

void Publisher::detach(ISubscriber &sub) {}

void Publisher::notify(std::string message) {
    this->message = message;

    for(auto sub : _sub_list)
        sub->update(*this);
}