#include "Zombie.hpp"

Zombie::Zombie(void): name_("") {}

Zombie::Zombie(std::string name): name_(name) {}

Zombie::~Zombie() {
    std::cout
        << ("** Purification Ray burned out a Zombie called \"" + name_ + "\" **")
        << std::endl;
}

void    Zombie::announce(void) {
    std::cout
        << ("<" + name_ + "> BraiiiiiiinnnzzzZ...")
        << std::endl;
}
