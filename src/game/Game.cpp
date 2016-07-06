#include "Game.hpp"

#include <utility>


Game::Game():
    credits{0}
    {

}

Game::Game(std::string planetName):
    credits{0},
    planetName{planetName}
    {

}

Game::~Game() {
    //dtor
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

}

double Game::getAirVolume() const {
    double sum = 0;

    for (Building* b : buildings) {
        sum += b->getAirVolume();
    }

    return sum;
}

double Game::getCO2() const {
    return co2_volume / getAirVolume();
}

