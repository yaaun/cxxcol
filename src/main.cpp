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
    Commandlet* tempcmd = nullptr;


    //  Title screen.
    printTitle();
    //  Seed randgen.
    srand(time(nullptr));

    *stateptr = nullptr;

    while (running) {
        std::cout << prompt;
        std::cin >> command;

        if (tempcmd != nullptr) {
            tempcmd->runCommand(command);
            if (!tempcmd->keepRunning()) {
                delete tempcmd;
                tempcmd = nullptr;
            }
        } else {
            tempcmd = cmd->runCommand(command);
            running = cmd->keepRunning();

            //std::cout << tempcmd;

            //  For one-off tempcmds.
            if (tempcmd != nullptr) {
                tempcmd->runCommand("");

                if (!tempcmd->keepRunning()) {
                    delete tempcmd;
                    tempcmd = nullptr;
                }
            }
        }
    }

    delete *stateptr;
    delete stateptr;
    delete cmd;

    return 0;
}
