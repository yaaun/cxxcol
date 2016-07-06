#include <string>

#ifndef BUILDING_H
#define BUILDING_H


class Building {
    public:
        Building() {};
        virtual ~Building() {};

        const std::string& getName() const;
        int getHealth() const;
        int getMaxHealth() const;
        double getAirVolume() const;

        unsigned getEmployedWorkers() const;
        unsigned getEmployedSoldiers() const;
        unsigned getEmployedScientists() const;

        unsigned getMaxWorkers() const;
        unsigned getMaxSoldiers() const;
        unsigned getMaxScientists() const;


    protected:

    private:
        std::string name;
        int health, max_health;
        int power;
        double air_volume = 5;

        unsigned workers, soldiers, scientists;
};

#endif // BUILDING_H
