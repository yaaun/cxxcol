#include "print.hpp"


void printHelp() {
    std::cout << "List of game commands" << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << "exit - without saving" << std::endl;
    std::cout << "new - starts a new game" << std::endl;
    std::cout << "quit - same as exit" << std::endl;
}

void printTitle() {
    std::cout << "   _____  ____  __  ___      _                   " << std::endl;
    std::cout << "  / __\ \/ /\ \/ / / __\___ | | ___  _ __  _   _ " << std::endl;
    std::cout << " / /   \  /  \  / / /  / _ \| |/ _ \| '_ \| | | |" << std::endl;
    std::cout << "/ /___ /  \  /  \/ /__| (_) | | (_) | | | | |_| |" << std::endl;
    std::cout << "\____//_/\_\/_/\_\____/\___/|_|\___/|_| |_|\__, |" << std::endl;
    std::cout << "                                           |___/" << std::endl;
}
