#include <pybind11/pybind11.h>

#include "pybind11_example/observer/IPublisher.h"
#include "pybind11_example/observer/ISubscriber.h"
#include "pybind11_example/observer/publisher.h"

namespace py = pybind11;
using namespace pybind11_example;

class IPublisherTrampline : public IPublisher {
    public:
    using IPublisher::IPublisher;

    void attach(std::shared_ptr<ISubscriber> sub) override {
        PYBIND11_OVERLOAD_PURE(void, IPublisher, attach, sub);
    }

    void detach(std::shared_ptr<ISubscriber> sub) override {
        PYBIND11_OVERLOAD_PURE(void, IPublisher, detach, sub);
    }

    void notify(std::string msg) override {
        PYBIND11_OVERLOAD_PURE(void, IPublisher, notify, msg);
    }
};

class ISubscriberTrampoline : public ISubscriber {
   public:
    using ISubscriber::ISubscriber;

    void update(std::shared_ptr<IPublisher> pub) override {
        PYBIND11_OVERLOAD_PURE(void, ISubscriber, update, pub);
    }
};

PYBIND11_MODULE(observer, m) {
    // py::class_<IPublisher, IPublisherTrampline>(m, "IPublisher")
    //     .def(py::init<>())
    //     .def_readwrite("message", &Publisher::message)
    //     .def("attach", py::overload_cast<std::shared_ptr<ISubscriber>>(&IPublisher::attach))
    //     .def("attach", py::overload_cast<std::shared_ptr<ISubscriber>>(&IPublisher::attach))
    //     .def("notify", py::overload_cast<std::string>(&IPublisher::notify));

    py::class_<IPublisher, std::shared_ptr<IPublisher>>(m, "IPublisher");
    // py::class_<ISubscriber, std::shared_ptr<ISubscriber>>(m, "ISubscriber");

    py::class_<Publisher, IPublisher, std::shared_ptr<Publisher>>(m, "Publisher")
        .def(py::init<>())
        .def("attach", py::overload_cast<std::shared_ptr<ISubscriber>>(&Publisher::attach))
        .def("attach", py::overload_cast<std::shared_ptr<ISubscriber>>(&Publisher::attach))
        .def("notify", py::overload_cast<std::string>(&Publisher::notify));

    py::class_<ISubscriber, ISubscriberTrampoline, std::shared_ptr<ISubscriber>>(m, "ISubscriber")
        .def(py::init<>())
        .def("update", py::overload_cast<std::shared_ptr<IPublisher>>(&ISubscriber::update));
}