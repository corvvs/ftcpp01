#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main() {
    Zombie z = Zombie("yosuke");
    z.announce();

    Zombie *heap_z = newZombie("kawada");
    heap_z->announce();
    delete heap_z;

    randomChump("Mr. BIG");
}
