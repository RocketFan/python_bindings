from pybind11_example import simple_functions
from pybind11_example.player import Player

print(simple_functions.add(1, 2))

p = Player("Player", 10, 15)
p.print_all_stats()

print("test")