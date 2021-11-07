#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    try {
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
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "an exception has been catched." << std::endl;
    }
    return 1;
}
