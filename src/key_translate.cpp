#ifndef RLUTIL_H
#define RLUTIL_H
#include "rlutil/rlutil.h"
#endif

enum class KeyAction : int {
    BACK,
    CANCEL,
    ENTER,
    PREV,
    NEXT
};


KeyAction translate_keycode(int keycode) {
    KeyAction action;

    switch (keycode) {
    case rlutil::KEY_UP:
        action = KeyAction::PREV;
        break;
    case rlutil::KEY_DOWN:
        action = KeyAction::NEXT;
        break;
    case rlutil::KEY_ESCAPE:
        action = KeyAction::CANCEL;
        break;
    case rlutil::KEY_DELETE:
        action = KeyAction::BACK;
        break;
    }

    return action;
}
