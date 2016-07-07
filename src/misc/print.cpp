#include "print.hpp"
#include <iostream>


void printHeader(std::string& s) {
    std::cout << s << std::endl;

    for (int i = 0; i < s.size(); i++) {
        std::cout << '-';
    }

    std::cout << std::endl;
}

void printTitle() {
    std::cout << "   _____  ____  __  ___      _                   " << std::endl;
    std::cout << "  / __\\ \\/ /\\ \\/ / / __\\___ | | ___  _ __  _   _ " << std::endl;
    std::cout << " / /   \\  /  \\  / / /  / _ \\| |/ _ \\| '_ \\| | | |" << std::endl;
    std::cout << "/ /___ /  \\  /  \\/ /__| (_) | | (_) | | | | |_| |" << std::endl;
    std::cout << "\\____//_/\\_\\/_/\\_\\____/\\___/|_|\\___/|_| |_|\\__, |" << std::endl;
    std::cout << "                                           |___/" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}
