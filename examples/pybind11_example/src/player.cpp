#include "pybind11_example/player.h"

using namespace pybind11_example;

Player::Player(std::string &name, int health, int attack)
    : name(name), health(health), attack(attack) {}

void Player::hit(Player player) {
    this->health -= player.attack;
}

void Player::add_animal(std::string name, int health, int attack) {
    auto animal = std::make_shared<Player>(name, health, attack);
    animals.push_back(animal);
}

void Player::print_all_stats() {
    _print_stats(*this);
    std::cout << "Animals:" << std::endl;

    for (auto animal : animals)
        _print_stats(*animal);
}

void Player::_print_stats(Player &player) {
    std::cout << "Name: " << player.name << std::endl;
    std::cout << "Health: " << player.health << std::endl;
    std::cout << "Attack: " << player.attack << std::endl;
}