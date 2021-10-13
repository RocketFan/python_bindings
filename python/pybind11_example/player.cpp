#include "pybind11_example/player.h"

#include <pybind11/pybind11.h>

using namespace pybind11_example;
namespace py = pybind11;

PYBIND11_MODULE(player, m) {
    py::class_<Player>(m, "Player")
        .def_readwrite("animals", &Player::animals)
        .def(py::init<std::string &, int, int>())
        .def("hit", &Player::hit)
        .def("add_animal", &Player::add_animal)
        .def("print_all_stats", &Player::print_all_stats);
}