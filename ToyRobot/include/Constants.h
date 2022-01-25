#ifndef CONSTANTS_H
#define CONSTANTS_H

const int TABLE_MAX_X = 4;
const int TABLE_MAX_Y = 4;

enum Directions {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NONE
};

enum Commands {
    PLACE,
    MOVE,
    LEFT,
    RIGHT,
    REPORT,
    EXIT,
    INVALID
};

#endif // CONSTANTS_H
