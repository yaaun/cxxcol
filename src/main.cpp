#include <iostream>
#include <string>

#ifndef RLUTIL_H
#define RLUTIL_H
#include "rlutil/rlutil.h"
#endif

int main() {
    bool running = true;
    int keycode;
    KeyAction action;

    while (running) {
        keycode = rlutil::getkey();

        action = translate_keycode(keycode);


    }

    return 0;
}
