#include <iostream>
#include <string>

#include "global_defs.hpp"



int main() {
    bool running = true;
    std::string command;
    std::string prompt{"> "};
    UIState uistate = UIState::DEFAULT;

    while (running) {
        std::cout << prompt;
        std::cin >> command;

        if (uistate == UIState::QUIT_CONFIRM) {
            if (command == "Y") {
                running = false;
            } else {
                std::cout << "Exit canceled." << std::endl;
            }

            uistate = UIState::DEFAULT;
        } else if (uistate == UIState::DEFAULT) {
            if (command == "status") {

            } else if (command == "exit" || command == "quit") {
                std::cout << "Do you really want to exit? (input capital Y to confirm)" << std::endl;
                uistate = UIState::QUIT_CONFIRM;
            } else {
                std::cout << "Unknown command: " << command << std::endl;
            }
        }
    }

    return 0;
}
