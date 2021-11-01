#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):
    weapon_(weapon), name_(name) {}

void    HumanA::attack(void) {
    std::cout
        << name_
        << " attacks with his "
        << weapon_.getType()
        << std::endl;
}