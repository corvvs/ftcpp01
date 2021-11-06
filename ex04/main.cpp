#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <stdlib.h>

const std::string   read_all(
    const std::string& filename
) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::string("Error: can't open a file: ") + filename;
    }
    // if (is_directory(filename)) {
    //     throw std::string("Error: is a directory: ") + filename;
    // }
    std::ostringstream receiver;
    receiver << ifs.rdbuf();
    if (!ifs.good() || ifs.fail()) {
        throw std::string("Error: failed to read from the file: ") + filename;
    }
    return std::string(receiver.str());
}

void    replace_out(
    const std::string& body,
    const std::string& str_from,
    const std::string& str_to,
    std::ofstream& fout
) {
    std::size_t from_len = str_from.length();
    std::size_t find_from = 0;
    while (true) {
        std::size_t found_head = body.find(str_from, find_from);
        if (found_head == std::string::npos) {
            break;
        }
        // assumed that: find_from < found_head
        fout << body.substr(find_from, found_head - find_from);
        if (!fout.good()) {
            return;
        }
        fout << str_to;
        if (!fout.good()) {
            return;
        }
        find_from = found_head + from_len;
    }
    fout << body.substr(find_from);
}

void    replace(
    const std::string& filename_original,
    const std::string& str_from,
    const std::string& str_to
) {
    const std::string body = read_all(filename_original);
    const std::string filename_replaced = filename_original + ".replace";
    std::ofstream ofs(filename_replaced);
    // if (is_directory(filename_replaced)) {
    //     throw std::string("Error: is a directory: ") + filename_replaced;
    // }
    if (!ofs.is_open()) {
        throw std::string("Error: failed to open output file: ") + filename_replaced;
    }
    replace_out(body, str_from, str_to, ofs);
    if (!ofs.good()) {
        throw std::string("Error: failed to write to output file: ") + filename_replaced;
    }
}

int main(int argc, char **argv) {
    try {
        if (argc != 4) {
            throw std::string("Error: unexpected arguments");
        }
        std::string filename = std::string(argv[1]);
        std::string s1 = std::string(argv[2]);
        std::string s2 = std::string(argv[3]);
        if (filename.empty() || s1.empty() || s2.empty()) {
            throw std::string("Error: detected empty string");
        }
        replace(filename, s1, s2);
        return 0;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } catch (std::string& errstr) {
        std::cout << errstr << std::endl;
    }
    return 1;
}
