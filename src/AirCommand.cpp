#include "AirCommand.hpp"

#include <iostream>
#include <iomanip>

Commandlet* AirCommand::runCommand(std::string cmdstr) {
    Game* game = *state_ptr;

    double co2 = game->getCO2() * 100;
    std::string co2desc;
    std::list<Building*> scrubberList = game->getBuildingsByType("Scrubber");
    unsigned scrubCapacity = 0, scrubbers = 0;
    double usedCapacity;

    std::cout << std::setprecision(3);

    std::cout << "Colony atmosphere status" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Total air volume: " << game->getAirVolume() << "m^3" << std::endl;
    std::cout << "CO2 concentration: " << co2 << "% ";

    if (co2 >= 8) {
        co2desc = "EXTREME";
    } else if (co2 >= 5) {
        co2desc = "VERY HIGH";
    } else if (co2 >= 3) {
        co2desc = "HIGH";
    } else if (co2 >= 1) {
        co2desc = "excessive";
    } else if (co2 >= 0.5) {
        co2desc = "caution";
    } else if (co2 >= 0.1) {
        co2desc = "tolerable";
    } else {
        co2desc = "safe";
    }

    std::cout << "(" << co2desc << ")" << std::endl;

    for (Building* b : scrubberList) {
        scrubCapacity += b->getCapacity();
        scrubbers += 1;
    }

    usedCapacity = static_cast<double>(game->getPopulation()) / scrubCapacity;

    std::cout << scrubbers << " active scrubbers, with a combined capacity for " << scrubCapacity << " colonists." << std::endl;
    std::cout << "Currently running at " << (usedCapacity * 100) << "% of maximum ("
        << game->getPopulation() << "/" << scrubCapacity << ")." << std::endl;

    if (usedCapacity > 0.8) {
        std::cout << "Warning: running scrubbers above 80% nominal power increases risk of breakdowns." << std::endl;
    }
    return nullptr;
}

bool AirCommand::keepRunning() {
    return false;
}
