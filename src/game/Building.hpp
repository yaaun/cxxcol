#include <string>

#ifndef BUILDING_H
#define BUILDING_H


class Building {
    public:
        Building();
        virtual ~Building();

        const std::string& getName() const;
        int getHealth() const;
        int getMaxHealth() const;
        double getAirVolume() const;
    protected:

    private:
        std::string name;
        int health, max_health;
        int power;
        double air_volume = 5;
};

#endif // BUILDING_H
