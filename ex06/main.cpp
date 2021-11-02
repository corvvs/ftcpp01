#include "Karen.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout
            << "Error: unexpected argument"
            << std::endl;
        return 1;
    }
    Karen smith = Karen();
    smith.filter(std::string(argv[1]));
    return 0;
}
