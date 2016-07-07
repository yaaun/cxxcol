#include "Scrubber.hpp"

Scrubber::Scrubber() {
    name = "Scrubber";
    workers = 0;
    soldiers = 0;
    scientists = 0;
    capacity = 20;
    health = 100;
    max_health = 100;
    power = 20;
}


unsigned Scrubber::getCapacity() const {
    if (!broken) {
        return capacity;
    } else {
        return 0;
    }
}
