#include "Game.hpp"

#include <iostream>
#include <utility>

#include "game/Building.hpp"
#include "game/Barrack.hpp"
#include "game/Scrubber.hpp"


Game::Game()
    {

}

Game::Game(std::string planetName):
    planetName{planetName}
    {

}

Game::~Game() {
    for (auto v : building_register) {
        delete v.second;
    }
}

void Game::next() {

}

void Game::addCredits(long long creds) {
    credits += creds;
}

long long Game::getCredits() const {
    return credits;
}

void Game::setCredits(long long creds) {
    credits = creds;
}

std::string Game::getPlanetName() const {
    return planetName;
}

void Game::setPlanetName(std::string s) {
    planetName = s;
}

unsigned Game::getPopulation() const {
    return workers + soldiers + scientists;
}

unsigned Game::getWorkers() const {
    return workers;
}

unsigned Game::getSoldiers() const {
    return soldiers;
}

unsigned Game::getScientists() const {
    return scientists;
}

unsigned Game::getFreeWorkers() const {
    unsigned total = getWorkers();

    for (auto val : buildings) {
        total -= val.second->getEmployedWorkers();
    }

    return total;
}

unsigned Game::getFreeSoldiers() const {
    unsigned total = getSoldiers();

    for (auto val : buildings) {
        total -= val.second->getEmployedSoldiers();
    }

    return total;
}

unsigned Game::getFreeScientists() const {
    unsigned total = getScientists();

    for (auto val : buildings) {
        total -= val.second->getEmployedScientists();
    }

    return total;
}

double Game::getAirVolume() const {
    double sum = 0;

    for (auto val : buildings) {
        sum += val.second->getAirVolume();
    }

    return sum;
}

double Game::getCO2() const {
    return co2_volume / getAirVolume();
}

unsigned Game::getScrubberCapacity() const {
    auto iter = buildings.find("Scrubber");
    unsigned cap = 0;

    for (; iter != buildings.end(); iter++) {
        cap += iter->second->getCapacity();
    }

    return cap;
}

unsigned Game::getPowerCapacity() const {
    auto iter = buildings.find("Generator");
    unsigned cap = 0;

    for (; iter != buildings.end(); iter++) {
        cap += iter->second->getCapacity();
    }

    return cap;
}

std::list<Building*> Game::getBuildingsByType(std::string type) {
    auto iter = buildings.find(type);
    std::list<Building*> results;

    for (; iter != buildings.end(); iter++) {
        results.push_back((*iter).second);
    }

    return results;
}

Building* Game::createBuilding(std::string type) {
    Building* ptr;

    if (type == "Barrack") {
        ptr = new Barrack;
        buildings.insert({type, ptr});
        building_register.insert({building_counter++, ptr});
    } else {
        std::cerr << "Internal error: invalid building type '" << type << "'" << std::endl;
        ptr = nullptr;
    }

    return ptr;
}
