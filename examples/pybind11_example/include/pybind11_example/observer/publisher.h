#pragma once

#include "pybind11_example/observer/IPublisher.h"

namespace pybind11_example {
class Publisher : public IPublisher {
   public:
    void attach(ISubscriber &sub);
    void detach(ISubscriber &sub);
    void notify(std::string msg);
};
}  // namespace pybind11_example