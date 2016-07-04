#include <iostream>
#include <string>

#ifndef RLUTIL_H
#define RLUTIL_H
#include "rlutil/rlutil.h"
#endif

#include "key_translate.hpp"

int main() {
    bool running = true;
    int keycode;
    KeyAction action;

    while (running) {
        keycode = rlutil::getkey();

        std::cout << keycode << std::endl;

        action = translate_keycode(keycode);

        switch (action) {
        case KeyAction::PREV:
        case KeyAction::BACK:
            //running = false;
            //std::cout << "Running is " << running << std::endl;
            break;
        }
    }

    return 0;
}
