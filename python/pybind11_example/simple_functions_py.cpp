#include <pybind11_example/simple_functions.h>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11_example;

PYBIND11_MODULE(simple_functions, m) {
    m.doc() = "This is doc file for this module";
    m.def("add", &add);
}