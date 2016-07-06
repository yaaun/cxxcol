#include <cstdlib>
#include <string>


/**
    Makes a randomized name for the planetoid. The resulting string is 7
    characters long, and consists of a 1 to 4-letter prefix, a hyphen "-",
    and numerics to fill the rest.
*/
std::string randomPlanetoidName(int len = 7) {
    std::string name;
    int i;

    int prefix_len = std::rand() % 4 + 1;
    int remain_len = len - prefix_len - 1;

    for (i = 0; i < prefix_len; i++) {
        name += (char) (std::rand() % 26 + 65);
    }

    name += '-';

    for (i = 0; i < remain_len; i++) {
        name += std::rand() % 10 + 48;
    }

    return name;
}
