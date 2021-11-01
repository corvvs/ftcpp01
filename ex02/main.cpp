#include <iostream>
#include <string>

int main() {
    std::string stringOriginal = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringOriginal;
    std::string &stringREF = stringOriginal;
    std::cout << "addr of Original: " << &stringOriginal << std::endl;
    std::cout << "addr thuru PTR:   " << stringPTR << std::endl;
    std::cout << "addr thuru REF:   " << &stringREF << std::endl;
    std::cout << "string thuru PTR: \"" << *stringPTR << "\"" << std::endl;
    std::cout << "string thuru REF: \"" << stringREF << "\"" << std::endl;
}
