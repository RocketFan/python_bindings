#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace pybind11_example {
class Player {
   public:
    std::string name;
    int health;
    int attack;
    std::vector<std::shared_ptr<Player>> animals;

    Player(std::string &name, int health, int attack);

    void hit(Player player);

    void add_animal(std::string name, int health, int attack);

    void print_all_stats();

   private:
    void _print_stats(Player &player);
};
}  // namespace pybind11_example