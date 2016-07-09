#include "NewCommand.hpp"

#include <iostream>
#include "misc/randgen.hpp"

Commandlet* NewCommand::runCommand(std::string cmdstr) {
    std::string planetName = randomPlanetoidName();
    std::string newName;
    bool chosen = false;
    char choice;

    if (*state_ptr != nullptr) {
        std::cout << "Warning: it appears that there is already an active game underway." << std::endl
            << "Starting a new game will delete unsaved progress. Continue? (Y/any) ";
        std::cin >> choice;

        if (choice != 'Y') {
            finished = true;
            return nullptr;
        }
    }

    std::cout << "Start colony on " << planetName << " or enter own name (enter '*' to roll again, or any"
        << std::endl << "other single character to accept): ";
    std::cin >> newName;

    if (newName == "*") {
        while (!chosen) {
            planetName = randomPlanetoidName();
            std::cout << std::endl << planetName << ". OK? (y/any): ";
            std::cin >> choice;

            if (choice == 'y') {
                chosen = true;
            }
        }
    } else if (newName.size() > 1) {
        planetName = newName;
    }

    std::cout << std::endl << "Planetoid will be called " << planetName << "." << std::endl;
    *state_ptr = new Game{planetName};
    finished = true;



    return nullptr;
}

bool NewCommand::keepRunning() {
    return !finished;
}
