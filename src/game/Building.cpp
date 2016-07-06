#include "Building.hpp"

Building::Building() {
    //ctor
}

Building::~Building() {
    //dtor
}

const std::string& Building::getName() const {

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
