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

Weapon&     HumanA::getWeapon(void) const {
    return weapon_;
}

std::string HumanA::getName(void) const {
    return name_;
}
