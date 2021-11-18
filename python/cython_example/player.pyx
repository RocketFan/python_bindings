# distutils: language = c++
cimport cython
from libcpp.string cimport string

cdef extern from "<cython_example/player.h>" namespace "cython_example":
    cdef cppclass CppPlayer "cython_example::Player":
        CppPlayer() except +
        CppPlayer(char *name, int health, int attack) except +
        void hit(CppPlayer player)
        void add_animal(str name, int health, int attack)
        void print_all_stats()

cdef class Player:
    cdef CppPlayer cpp_player

    def __cinit__(self, char *name, int health, int attack):
        # name = name.encode()
        self.cpp_player = CppPlayer(name, health, attack)

    # def hit(self, player):
    #     player 
    #     self.cpp_player.hit(player)

    def add_animal(self, char *name, health, attack):
        # name = name.encode()
        self.cpp_player.add_animal(name, health, attack)

    def print_all_stats(self):
        self.cpp_player.print_all_stats()