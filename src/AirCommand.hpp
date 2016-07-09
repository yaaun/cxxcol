#ifndef AIRCOMMAND_H
#define AIRCOMMAND_H

#include "Commandlet.hpp"


class AirCommand : public Commandlet
{
    public:
        AirCommand(Game** stateptr):
            Commandlet{"air", stateptr} {}

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
};

#endif // AIRCOMMAND_H
