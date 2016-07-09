#ifndef BARRACK_H
#define BARRACK_H

#include "Building.hpp"


class Barrack : public Building {
    public:
        Barrack() {}
        virtual ~Barrack() {}

        virtual unsigned getCapacity() override;
        virtual unsigned getPowerUsage() override;

    protected:

    private:
};

#endif // BARRACK_H
