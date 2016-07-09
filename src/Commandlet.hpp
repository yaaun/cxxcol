#ifndef COMMANDLET_H
#define COMMANDLET_H

#include <string>
#include "game/Game.hpp"


class Commandlet {
    public:
        Commandlet(std::string name, Game** stateptr):
            state_ptr{stateptr},
            name{name} {}
        virtual ~Commandlet() {};

        virtual Commandlet* runCommand(std::string) = 0;
        virtual bool keepRunning();
        virtual const std::string& getName() const {return name;}
    protected:
        Game** state_ptr;
        std::string name;
    private:
};

#endif // COMMANDLET_H
