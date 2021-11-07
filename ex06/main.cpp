#include "Karen.hpp"

int main(int argc, char **argv) {
    switch (argc) {
        case 2: {
            Karen smith = Karen();
            smith.filter(std::string(argv[1]));
            return 0;
        }
        default:
            std::cout
                << "Error: unexpected argument"
                << std::endl;
            return 1;
    }
}
