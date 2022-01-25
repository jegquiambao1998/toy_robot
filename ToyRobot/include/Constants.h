#ifndef CONSTANTS_H
#define CONSTANTS_H

const int TABLE_X = 5;
const int TABLE_Y = 5;

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
