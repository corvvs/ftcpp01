#include "HumanB.hpp"

HumanB::HumanB(std::string name):
    weapon_(NULL), name_(name) {}

void    HumanB::setWeapon(Weapon *weapon) {
    weapon_ = weapon;
}

void    HumanB::attack(void) {
    if (!weapon_) {
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
