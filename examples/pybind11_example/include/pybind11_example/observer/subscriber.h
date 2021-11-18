#pragma once

#include "pybind11_example/observer/ISubscriber.h"

namespace pybind11_example {
class Subscriber : public ISubscriber {
   public:
    void update(std::shared_ptr<IPublisher> pub);
};
}  // namespace pybind11_example