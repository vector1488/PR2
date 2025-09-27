#include "decrypt.h"
#include "encrypt.h"
#include "ssssen.h"
#include "shamir.h"
#include <cstdlib>
#include <filesystem>
#include <iostream>


namespace fs = std::filesystem;



void show_usage(int argc, char** argv) {
    std::cerr << "Usage:\n"
        << "  " << argv[0] << " e(ncrypt) <file_path>\n"
        << "  " << argv[0] << " d(ecrypt) <file_path>\n";
}


int shamir() {
    std::string file_path;
    char mode;

    std::cout << "Enter mode (e - encrypt, d - decrypt): ";
    std::cin >> mode;

    std::cout << "Enter file path: ";
    std::cin >> file_path;

    if (mode == 'e') {
        int res = encrypt(file_path);
        if (res != 0) {
            std::cerr << "Error encrypting: " << file_path << std::endl;
        }
    } else if (mode == 'd') {
        decrypt(file_path);
    } else {
        std::cerr << "Unknown mode. Use 'e' or 'd'.\n";
    }

    return 0;
}
