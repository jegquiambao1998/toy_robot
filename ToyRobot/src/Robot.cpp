#include <cstring>
#include <iostream>

#include "Robot.h"
#include "helpers.cpp"


Robot::Robot() : isRobotInitialized(false) {
    //ctor
}


Robot::~Robot() {
    //dtor
}


void Robot::displayCommandList() {
    std::cout << "Command List:" << std::endl;
    std::cout << "PLACE x,y,Direction" << std::endl;
    std::cout << "MOVE" << std::endl;
    std::cout << "LEFT" << std::endl;
    std::cout << "RIGHT" << std::endl;
    std::cout << "REPORT" << std::endl;
    std::cout << "EXIT" << std::endl << std::endl;
}


void Robot::startProcess() {
    std::cout << "Toy Robot" << std::endl << std::endl;
    displayCommandList();

    std::string inputtedCommand;

    while(true) {
        std::cout << "Enter Command: ";
        getline(std::cin >> std::ws, inputtedCommand);

        Commands command = convertStringToCommand(inputtedCommand);

        if (command == EXIT) {
            std::cout << "Stopping Process..." << std::endl << std::endl;
            break;
        }

        if (command == INVALID) {
            std::cout << "Command not recognized!" << std::endl << std::endl;
            continue;
        }

        if (!IsRobotInitialized() && (command != EXIT && command != PLACE)) {
            std::cout << "Robot has not been placed on the table! Ignoring..." << std::endl << std::endl;
            continue;
        }

        switch(command) {
            case PLACE:
                std::cout << "PLACE";
                break;

            case REPORT:
                reportLocation();
                break;

            default: std::cout << "Invalid Command!" << std::endl << std::endl;
        }
    }
}


void Robot::reportLocation()
{
    std::cout << x << "," << y << "," << convertDirectionToString(direction);
}


void Robot::setIsRobotInitialized(bool _isRobotInitialized)
{
    isRobotInitialized = _isRobotInitialized;
}


bool Robot::IsRobotInitialized()
{
    return isRobotInitialized;
}


void Robot::initializeRobot(
    int initialX,
    int initialY,
    Directions initialDirection
)
{
    x = initialX;
    y = initialY;
    direction = initialDirection;
}
