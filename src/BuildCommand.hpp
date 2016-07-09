#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Commandlet.hpp"


class BuildCommand : public Commandlet
{
    public:
        BuildCommand(Game** stateptr):
            Commandlet{"build", stateptr} {}

        virtual Commandlet* runCommand(std::string) override;
        virtual bool keepRunning() override;
    protected:

    private:
};

#endif // BUILDCOMMAND_H
