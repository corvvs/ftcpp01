#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main() {
    try {
        Zombie z = Zombie("yosuke");
        z.announce();

        Zombie *heap_z = newZombie("kawada");
        heap_z->announce();
        delete heap_z;

        randomChump("Mr. BIG");
        return 0;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "an exception has been catched." << std::endl;
    }
    return 1;
}
