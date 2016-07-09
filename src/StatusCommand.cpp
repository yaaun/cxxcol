#include "StatusCommand.hpp"

#include <iostream>
#include <iomanip>

Commandlet* StatusCommand::runCommand(std::string cmdstr) {
        std::cout << std::setprecision(3);
        double co2 = (**state_ptr).getCO2() * 100;


        if (co2 >= 8) {
            std::cout << "DANGER: EXTREME CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 5) {
            std::cout << "DANGER: VERY HIGH CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 3) {
            std::cout << "DANGER: HIGH CO2 CONCENTRATION (" << co2 << "%)" << std::endl << std::endl;
        } else if (co2 >= 1) {
            std::cout << "Warning: excessive CO2 concentration (" << co2 << "%)" << std::endl << std::endl;
        }

        return nullptr;
}

bool StatusCommand::keepRunning() {
    return false;
}
