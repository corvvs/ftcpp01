#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }
    Zombie *zs = new Zombie[N];
    for (int i = 0; i < N; i += 1) {
        zs[i].setName(name);
    }
    return zs;
}
