#pragma once

#include <memory>
#include <string>
#include <vector>

namespace pybind11_example {
class ISubscriber;

class IPublisher {
   public:
    std::string message;

    virtual void attach(std::shared_ptr<ISubscriber> sub) = 0;
    virtual void detach(std::shared_ptr<ISubscriber> sub) = 0;
    virtual void notify(std::string msg) = 0;

   protected:
    std::vector<std::shared_ptr<ISubscriber>> _sub_list;
};
}  // namespace pybind11_example