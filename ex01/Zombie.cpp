#include "Zombie.hpp"

Zombie::Zombie(void): name_("") {}

Zombie::Zombie(std::string name): name_(name) {}

Zombie::~Zombie() {
    std::cout
        << ("** Purification Ray burned out a Zombie called \"" + name_ + "\" **")
        << std::endl;
}

void    Zombie::announce(void) const {
    std::cout
        << ("<" + name_ + "> BraiiiiiiinnnzzzZ...")
        << std::endl;
}

std::string Zombie::getName(void) const {
    return name_;
}

void    Zombie::setName(std::string name) {
    name_ = name;
}
