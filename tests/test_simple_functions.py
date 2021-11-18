import pytest

from pybind11_example import simple_functions

def test_add():
    assert simple_functions.add(2, 5) == 7