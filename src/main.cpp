#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "global_defs.hpp"
#include "Commandlet.hpp"
#include "DefaultCommand.hpp"

#include "game/Game.hpp"
#include "misc/print.hpp"

int main() {
    bool running = true;
    std::string command;
    std::string prompt{"> "};
    Game** stateptr = new Game*;
    Commandlet* cmd = new DefaultCommand{stateptr};
    Commandlet* tempcmd = cmd;


    //  Title screen.
    printTitle();
    //  Seed randgen.
    srand(time(nullptr));

    *stateptr = nullptr;

    while (running) {
        std::cout << prompt;
        std::cin >> command;

        cmd->runCommand(command);
        running = cmd->keepRunning();

        if (tempcmd != cmd) {
            delete cmd;
            cmd = tempcmd;
        }
    }

    delete *stateptr;
    delete stateptr;
    delete cmd;

    return 0;
}
