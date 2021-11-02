#include <iostream>
#include <string>

int main() {
    std::string stringOriginal = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringOriginal;
    std::string &stringREF = stringOriginal;
    std::cout << "addr of Original: " << &stringOriginal << std::endl;
    std::cout << "addr thru PTR:   " << stringPTR << std::endl;
    std::cout << "addr thru REF:   " << &stringREF << std::endl;
    std::cout << "string thru PTR: \"" << *stringPTR << "\"" << std::endl;
    std::cout << "string thru REF: \"" << stringREF << "\"" << std::endl;
}
