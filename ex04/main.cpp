#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const std::string   *read_all(
    const std::string& filename
) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        ifs.close();
        return NULL;
    }
    std::ostringstream receiver;
    receiver << ifs.rdbuf();
    ifs.close();
    return new std::string(receiver.str());
}

bool    replace_out(
    const std::string& body,
    const std::string& str_from,
    const std::string& str_to,
    std::ofstream& fout
) {
    std::size_t body_len = body.length();
    std::size_t from_len = str_from.length();
    std::size_t find_head = 0;
    while (true) {
        std::size_t found_head = body.find(str_from, find_head);
        if (found_head == std::string::npos) {
            fout << body.substr(find_head, body_len - find_head);
            break;
        }
        fout << body.substr(find_head, found_head - find_head);
        if (fout.bad()) {
            break;
        }
        fout << str_to;
        if (fout.bad()) {
            break;
        }
        find_head = found_head + from_len;
    }
    return fout.bad() == false;
}

bool    replace(
    const std::string& filename_original,
    const std::string& str_from,
    const std::string& str_to
) {
    const std::string *body = read_all(filename_original);
    if (!body) {
        std::cout
            << "Error: failed to read from input file: "
            << filename_original
            << std::endl;
        return false;
    }
    const std::string filename_replaced = filename_original + ".replace";
    std::ofstream ofs(filename_replaced);
    if (!ofs.is_open()) {
        std::cout
            << "Error: failed to open output file: "
            << filename_replaced
            << std::endl;
        delete body;
        return false;
    }

    bool out_succeeded =  replace_out(*body, str_from, str_to, ofs);
    delete body;
    if (!out_succeeded) {
        std::cout
            << "Error: failed to write to output file: "
            << filename_replaced
            << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Error: unexpected arguments" << std::endl;
        return 1;
    }
    std::string filename = std::string(argv[1]);
    std::string s1 = std::string(argv[2]);
    std::string s2 = std::string(argv[3]);
    if (filename.empty() || s1.empty() || s2.empty()) {
        std::cout << "Error: detected empty string" << std::endl;
        return 1;
    }
    bool replace_succeeded = replace(filename, s1, s2);
    if (!replace_succeeded) {
        return 1;
    }
    return 0;
}
