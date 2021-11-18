from cython_example import simple_functions
from cython_example.player import Player

print(simple_functions.add(1, 2))

p = Player("Player", 10, 15)
p.print_all_stats()

print("test")