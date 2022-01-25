#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include "Constants.h"

std::string convertDirectionToString(Directions direction) {
    switch(direction) {
        case NORTH: return "NORTH";
        case SOUTH: return "SOUTH";
        case EAST: return "EAST";
        case WEST: return "WEST";
        default: return "Invalid";
    }
}

Directions convertStringToDirection(std::string direction) {
    transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

    if (direction == "NORTH") return NORTH;
    else if (direction == "SOUTH") return SOUTH;
    else if (direction == "EAST") return EAST;
    else if (direction == "WEST") return WEST;
    else return NONE;
}

Commands convertStringToCommand(std::string command) {
    transform(command.begin(), command.end(), command.begin(), ::toupper);

    if (command == "MOVE") return MOVE;
    else if (command == "LEFT") return LEFT;
    else if (command == "RIGHT") return RIGHT;
    else if (command == "REPORT") return REPORT;
    else if (command == "EXIT") return EXIT;
    else {
        std::stringstream ss(command);
        std::string commandFragment;
        std::vector<std::string> commandVector;

        while (ss >> commandFragment) {
            commandVector.push_back(commandFragment);
        }

        if (commandVector.at(0) != "PLACE" || commandVector.size() != 2) return INVALID;

        std::istringstream iss(commandVector.at(1));
        std::vector<std::string> placeValuesVector;

        while (getline(iss, commandFragment, ',')) {
            placeValuesVector.push_back(commandFragment);
        }

        if (placeValuesVector.size() != 3) return INVALID;

        return PLACE;
    }

    return INVALID;
}
