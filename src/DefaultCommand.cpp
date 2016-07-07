#include <iostream>
#include <iomanip>
#include <string>

#include "Commandlet.hpp"
#include "DefaultCommand.hpp"
#include "game/Game.hpp"
#include "game/Building.hpp"
#include "misc/print.hpp"
#include "misc/randgen.hpp"

bool DefaultCommand::keepRunning() {
    return run;
}

Commandlet* DefaultCommand::runCommand(std::string cmd) {
    Game* const game = *state_ptr; //  For convenience.
    bool statePresent;

    if (game != nullptr) {
        statePresent = true;
    }

    if (cmd == "help") {
        std::cout << "Default mode commands" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "air - display information about the state of the atmosphere within the colony" << std::endl;
        std::cout << "exit - without saving" << std::endl;
        std::cout << "help - this help message" << std::endl;
        std::cout << "new - start new game" << std::endl;
        std::cout << "next - end turn, and advance the time by another 14 days" << std::endl;
        std::cout << "pop - display colony population report" << std::endl;
        std::cout << "quit - same as exit" << std::endl;
        std::cout << std::endl;
    } else if (cmd == "air" && statePresent) {
        double co2 = game->getCO2() * 100;
        std::string co2desc;
        std::list<Building*> scrubberList = game->getBuildingsByType("Scrubber");
        unsigned scrubCapacity = 0, scrubbers = 0;
        double usedCapacity;

        std::cout << std::setprecision(3);

        std::cout << "Colony atmosphere status" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Total air volume: " << game->getAirVolume() << "m^3" << std::endl;
        std::cout << "CO2 concentration: " << co2 << "% ";

        if (co2 >= 8) {
            co2desc = "EXTREME";
        } else if (co2 >= 5) {
            co2desc = "VERY HIGH";
        } else if (co2 >= 3) {
            co2desc = "HIGH";
        } else if (co2 >= 1) {
            co2desc = "excessive";
        } else if (co2 >= 0.5) {
            co2desc = "caution";
        } else if (co2 >= 0.1) {
            co2desc = "tolerable";
        } else {
            co2desc = "safe";
        }

        std::cout << "(" << co2desc << ")" << std::endl;

        for (Building* b : scrubberList) {
            scrubCapacity += b->getCapacity();
            scrubbers += 1;
        }

        usedCapacity = static_cast<double>(game->getPopulation()) / scrubCapacity;

        std::cout << scrubbers << " active scrubbers, with a combined capacity for " << scrubCapacity << " colonists." << std::endl;
        std::cout << "Currently running at " << (usedCapacity * 100) << "% of maximum ("
            << game->getPopulation() << "/" << scrubCapacity << ")." << std::endl;

        if (usedCapacity > 0.8) {
            std::cout << "Warning: running scrubbers above 80% nominal power increases risk of breakdowns." << std::endl;
        }
    } else if (cmd == "power" && statePresent) {

    } else if (cmd == "status" && statePresent) {
        std::cout << std::setprecision(3);
        double co2 = game->getCO2() * 100;

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
        game->next();
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
    } else if (cmd == "pop" && statePresent) {
        std::cout << "Colony population report" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Workers: " << game->getWorkers() << " total, " << game->getFreeWorkers() << " idle" << std::endl;
        std::cout << "Soldiers: " << game->getSoldiers() << " total, " << game->getFreeSoldiers() << " idle" << std::endl;
        std::cout << "Scientists: " << game->getScientists() << " total, " << game->getFreeScientists() << " idle" << std::endl << std::endl;
        std::cout << "Total population: " << game->getPopulation() << std::endl;
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
