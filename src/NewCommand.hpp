#ifndef NEWCOMMAND_HPP
#define NEWCOMMAND_HPP

#include "Commandlet.hpp"


class NewCommand : public Commandlet
{
    public:
        NewCommand(Game** stateptr):
            Commandlet{"new", stateptr} {}

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
        bool finished = false;
};

#endif // NEWCOMMAND_HPP
