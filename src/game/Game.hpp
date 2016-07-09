#include <list>
#include <map>
#include <string>

#include "Building.hpp"
#include "Resource.hpp"

#ifndef GAME_H
#define GAME_H


class Game {
    public:
        Game();
        Game(std::string planetName);
        ~Game();

        /// Ends the turn.
        void next();
        unsigned getTurnCount() const;

        void addCredits(long long);
        long long getCredits() const;
        void setCredits(long long);

        std::string getPlanetName() const;
        void setPlanetName(std::string);


        double getAirVolume() const;
        double getCO2() const;

        unsigned getPopulation() const;
        unsigned getWorkers() const;
        unsigned getSoldiers() const;
        unsigned getScientists() const;

        unsigned getFreeWorkers() const;
        unsigned getFreeSoldiers() const;
        unsigned getFreeScientists() const;

        unsigned getScrubberCapacity() const;
        unsigned getPowerCapacity() const;

        std::list<Building*> getBuildingsByType(std::string type);
        unsigned countBuildingsByType(std::string type);

        Building* createBuilding(std::string type);
    protected:

    private:
        long long credits = 0;
        unsigned turn_counter = 0;
        unsigned building_counter = 1;

        std::map<unsigned, Building*> building_register;
        std::multimap<std::string, Building*> buildings;
        std::string planetName;
        std::map<std::string, Resource> resources;

        double co2_volume = 0;
        unsigned workers = 0, soldiers = 0, scientists = 0;
};

#endif // GAME_H
