#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <sys/stat.h>

bool    is_directory(const std::string& filename) {
    struct stat	sb;

    int rv = stat(filename.c_str(), &sb);
    if (rv < 0 || S_ISDIR(sb.st_mode))
    {
        return true;
    }
    return false;
}

const std::string   read_all(
    const std::string& filename
) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::string("Error: can't open a file: ") + filename;
    }
    if (is_directory(filename)) {
        ifs.close();
        throw std::string("Error: is a directory: ") + filename;
    }
    std::ostringstream receiver;
    receiver << ifs.rdbuf();
    if (!ifs.good() || ifs.fail()) {
        ifs.close();
        throw std::string("Error: failed to read from the file: ") + filename;
    }
    ifs.close();
    return std::string(receiver.str());
}

void    replace_out(
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
        if (!fout.good()) {
            break;
        }
        fout << str_to;
        if (!fout.good()) {
            break;
        }
        find_head = found_head + from_len;
    }
}

void    replace(
    const std::string& filename_original,
    const std::string& str_from,
    const std::string& str_to
) {
    const std::string body = read_all(filename_original);
    const std::string filename_replaced = filename_original + ".replace";
    std::ofstream ofs(filename_replaced);
    if (is_directory(filename_replaced)) {
        throw std::string("Error: is a directory: ") + filename_replaced;
    }
    if (!ofs.is_open()) {
        throw std::string("Error: failed to open output file: ") + filename_replaced;
    }
    replace_out(body, str_from, str_to, ofs);
    bool out_succeeded = ofs.good();
    ofs.close();
    if (!out_succeeded) {
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
