#pragma once

namespace pybind11_example {
class IPublisher;

class ISubscriber {
   public:
    virtual void update(IPublisher &pub) = 0;
};
}  // namespace pybind11_example