#include <iostream>
#include <iomanip>
#include <string>

#include "Commandlet.hpp"
#include "DefaultCommand.hpp"
#include "AirCommand.hpp"
#include "NewCommand.hpp"
#include "PowerCommand.hpp"
#include "StatusCommand.hpp"

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
    Commandlet* tempcmd = nullptr;

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
        tempcmd = new AirCommand{state_ptr};
    } else if (cmd == "build" && statePresent) {
        tempcmd = new BuildCommand{state_ptr};
    } else if (cmd == "power" && statePresent) {
        tempcmd = new PowerCommand{state_ptr};
    } else if (cmd == "status" && statePresent) {
        tempcmd = new StatusCommand{state_ptr};
    } else if (cmd == "next" && statePresent) {
        game->next();
    } else if (cmd == "new") {
        tempcmd = new NewCommand{state_ptr};
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

    return tempcmd;
}
