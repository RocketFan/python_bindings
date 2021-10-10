# distutils: language = c++
cimport cython

cdef extern from "<cython_example/simple_functions.h>":
    float cpp_add "cython_example::add" (float a, float b)

def add(a: float, b: float) -> float:
    return cpp_add(a, b)