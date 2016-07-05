#include "print.hpp"

#ifndef RLUTIL_H
#define RLUTIL_H
#include "rlutil.h"
#endif

void printCommand(std::string& cmdstr, int xpos, int ypos) {
    for (unsigned i = 0; i < cmdstr.size(); i++) {
        rlutil::locate(xpos + i, ypos);
        rlutil::setChar(cmdstr[i]);
        //std::cout << "xpos = " << xpos << ", ypos = " << ypos << std::endl;
    }
}

void printPrompt(std::string& promptstr, std::string& cmdstr, int xpos, int ypos) {
    std::string cat{promptstr};
    cat += cmdstr;
    printCommand(cat, xpos, ypos);
}

void clearLine(int row) {
    int width = rlutil::tcols();

    for (int i = 0; i < width; i++) {
        rlutil::locate(row, i + 1);
        rlutil::setChar(' ');
    }
}
