#ifndef SCRUBBER_H
#define SCRUBBER_H

#include "Building.hpp"


class Scrubber : public Building {
    public:
        Scrubber();
        virtual ~Scrubber() {};

        virtual unsigned getCapacity() const override;

    protected:

    private:

};

#endif // SCRUBBER_H
