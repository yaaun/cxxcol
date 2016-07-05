#include "Game.hpp"

Game::Game():
    credits{0}
    {
}

Game::~Game() {
    //dtor
}

void Game::addCredits(long long creds) {
    credits += creds;
}

long long Game::getCredits() {
    return credits;
}

void Game::setCredits(long long creds) {
    credits = creds;
}
