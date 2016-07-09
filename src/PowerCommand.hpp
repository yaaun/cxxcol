#ifndef POWERCOMMAND_H
#define POWERCOMMAND_H

#include "Commandlet.hpp"


class PowerCommand : public Commandlet {
    public:
        PowerCommand(Game** stateptr):
            Commandlet{"Power", stateptr} {}

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
};

#endif // POWERCOMMAND_H
