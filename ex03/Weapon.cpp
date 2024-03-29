#include "Weapon.hpp"

Weapon::Weapon(std::string type): type_(type) {}

void                Weapon::setType(std::string type) {
    type_ = type;
}

const std::string&  Weapon::getType(void) const {
    return type_;
}
