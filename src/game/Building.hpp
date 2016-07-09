#include <string>

#ifndef BUILDING_H
#define BUILDING_H


class Building {
    public:
        Building() {};
        virtual ~Building() {};

        virtual const std::string& getName() const {return name;}
        virtual int getHealth() const {return health;}
        virtual int getMaxHealth() const {return max_health;}
        virtual double getAirVolume() const {return air_volume;}

        virtual unsigned getEmployedWorkers() const {return workers;}
        virtual unsigned getEmployedSoldiers() const {return soldiers;}
        virtual unsigned getEmployedScientists() const {return scientists;}

        virtual unsigned getCapacity() const = 0;
        virtual unsigned getPowerUsage() const = 0;

        virtual bool isBroken() const {return broken;}
        virtual void setBroken(bool brk) {broken = brk;}
    protected:
        std::string name;
        int health, max_health;
        int power;
        double air_volume = 5;
        bool broken = false;

        unsigned capacity;
        unsigned workers, soldiers, scientists;
    private:
};

#endif // BUILDING_H
