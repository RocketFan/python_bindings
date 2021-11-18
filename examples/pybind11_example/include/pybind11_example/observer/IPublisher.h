#pragma once

#include <string>
#include <vector>

namespace pybind11_example {
class ISubscriber;

class IPublisher {
   public:
    std::string message;

    virtual void attach(ISubscriber &sub) = 0;
    virtual void detach(ISubscriber &sub) = 0;
    virtual void notify(std::string msg) = 0;

   protected:
    std::vector<ISubscriber*> _sub_list;
};
}  // namespace pybind11_example