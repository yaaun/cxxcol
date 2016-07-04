enum class KeyAction : int {
    BACK,
    CANCEL,
    ENTER,
    PREV,
    NEXT
};

KeyAction translate_keycode(int);
