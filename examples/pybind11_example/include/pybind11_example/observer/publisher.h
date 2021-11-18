#pragma once

#include "pybind11_example/observer/IPublisher.h"

namespace pybind11_example {
class Publisher : public std::enable_shared_from_this<Publisher>, public IPublisher {
   public:
    void attach(std::shared_ptr<ISubscriber> sub);
    void detach(std::shared_ptr<ISubscriber> sub);
    void notify(std::string msg);
};
}  // namespace pybind11_example