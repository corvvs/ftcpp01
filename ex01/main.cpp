#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 10;
    Zombie *zs = zombieHorde(N, "yokawada");
    if (!zs) {
        return (1);
    }
    for (int i = 0; i < N; i += 1) {
        zs[i].announce();
    }
    delete[] zs;
    return (0);
}
