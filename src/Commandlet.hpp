#ifndef COMMANDLET_H
#define COMMANDLET_H

#include <string>
#include "game/Game.hpp"


class Commandlet {
    public:
        Commandlet(Game** stateptr):
            state_ptr{stateptr} {}
        virtual ~Commandlet() {};

        virtual Commandlet* runCommand(std::string) = 0;
        virtual bool keepRunning();
    protected:
        Game** state_ptr;
    private:
};

#endif // COMMANDLET_H
