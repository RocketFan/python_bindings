#pragma once

#include "pybind11_example/observer/ISubscriber.h"

namespace pybind11_example {
class Subscriber : public ISubscriber {
   public:
    void update(IPublisher &pub);
};
}  // namespace pybind11_example