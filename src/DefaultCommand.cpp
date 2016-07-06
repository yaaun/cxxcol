#include <iostream>
#include <iomanip>
#include <string>

#include "Commandlet.hpp"
#include "DefaultCommand.hpp"
#include "game/Game.hpp"
#include "misc/randgen.hpp"

bool DefaultCommand::keepRunning() {
    return run;
}

Commandlet* DefaultCommand::runCommand(std::string cmd) {
    Game* const state = *state_ptr; //  For convenience.
    bool statePresent;

    if (state != nullptr) {
        statePresent = true;
    }

    if (cmd == "help") {
        std::cout << "Default mode commands" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "exit - without saving" << std::endl;
        std::cout << "help - this help message" << std::endl;
        std::cout << "new - start new game" << std::endl;
        std::cout << "quit - same as exit" << std::endl;
        std::cout << std::endl;
    } else if (cmd == "status" && statePresent) {
        std::cout << std::setprecision(3);
        double co2 = state->getCO2() * 100;

        if (co2 >= 8) {
            std::cout << "DANGER: EXTREME CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 5) {
            std::cout << "DANGER: VERY HIGH CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 3) {
            std::cout << "DANGER: HIGH CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 1) {
            std::cout << "Warning: excessive CO2 concentration (" << co2 << "%)" << std::endl << std::endl;
        }


    } else if (cmd == "next" && statePresent) {
        state->next();
    } else if (cmd == "new") {
        std::string planetName = randomPlanetoidName();
        std::string newName;
        bool chosen = false;
        char choice;

        if (*state_ptr != nullptr) {
            std::cout << "Warning: it appears that there is already an active game underway." << std::endl
                << "Starting a new game will delete unsaved progress. Continue? (Y/any) ";
            std::cin >> choice;

            if (choice != 'Y') {
                goto abort_new;
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
    } else if (cmd == "exit" || cmd == "quit") {
        run = false;
    } else if (!statePresent
               && (cmd == "status" || cmd == "next")) {
        std::cout << "Error: no game in progress (start a new game with 'new' or load a save with 'load')" << std::endl;
    } else {
        std::cout << "Error: unknown command '" << cmd << "' (try 'help' if you don't know what to do)" << std::endl;
    }

    abort_new:

    return this;
}
