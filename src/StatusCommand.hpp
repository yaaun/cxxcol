#ifndef STATUSCOMMAND_H
#define STATUSCOMMAND_H

#include "Commandlet.hpp"


class StatusCommand : public Commandlet
{
    public:
        StatusCommand(Game** stateptr):
            Commandlet{"Status", stateptr} {}

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
};

#endif // STATUSCOMMAND_H
