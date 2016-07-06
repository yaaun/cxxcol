#ifndef DEFAULTCOMMAND_H
#define DEFAULTCOMMAND_H

#include "Commandlet.hpp"
#include "Game.hpp"


class DefaultCommand : public Commandlet {
    public:
        DefaultCommand(Game** stateptr):
            Commandlet{stateptr} {};
        virtual ~DefaultCommand() {};

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
        bool run{true};
};

#endif // DEFAULTCOMMAND_H
