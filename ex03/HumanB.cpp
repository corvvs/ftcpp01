#include "HumanB.hpp"

HumanB::HumanB(std::string name):
    weapon_(NULL), name_(name) {}

void    HumanB::setWeapon(Weapon* weapon) {
    weapon_ = weapon;
}

void    HumanB::attack(void) {
    if (!getWeapon()) {
        std::cout
            << name_
            << " beats with his own fists"
            << std::endl;
        return;
    }
    std::cout
        << name_
        << " attacks with his "
        << weapon_->getType()
        << std::endl;
}

Weapon*     HumanB::getWeapon(void) const {
    return weapon_;
}

std::string HumanB::getName(void) const {
    return name_;
}
