#include "Building.hpp"


const std::string& Building::getName() const {
    return name;
}

int Building::getHealth() const {
    return health;
}

int Building::getMaxHealth() const {
    return max_health;
}

double Building::getAirVolume() const {
    return air_volume;
}

unsigned Building::getEmployedWorkers() const {
    return workers;
}

unsigned Building::getEmployedSoldiers() const {
    return soldiers;
}

unsigned Building::getEmployedScientists() const {
    return scientists;
}

unsigned Building::getMaxWorkers() const {
    return 0;
}

unsigned Building::getMaxSoldiers() const {
    return 0;
}

unsigned Building::getMaxScientists() const {
    return 0;
}
