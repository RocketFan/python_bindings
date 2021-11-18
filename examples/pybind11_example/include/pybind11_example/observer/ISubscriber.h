#pragma once

#include <memory>

namespace pybind11_example {
class IPublisher;

class ISubscriber {
   public:
    virtual void update(std::shared_ptr<IPublisher> pub) = 0;
};
}  // namespace pybind11_example