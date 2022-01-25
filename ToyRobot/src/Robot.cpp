#include <cctype>
#include <cstring>
#include <iostream>

#include "Robot.h"
#include "helpers.cpp"

using std::cout;
using std::endl;
using std::string;


Robot::Robot() : isRobotInitialized(false) {
    //ctor
}


Robot::~Robot() {
    //dtor
}


void Robot::displayCommandList() {
    cout << "Command List:"         << endl;
    cout << "PLACE x,y,Direction"   << endl;
    cout << "MOVE"                  << endl;
    cout << "LEFT"                  << endl;
    cout << "RIGHT"                 << endl;
    cout << "REPORT"                << endl;
    cout << "EXIT"                  << endl << endl;
}


void Robot::startProcess() {
    cout << "Toy Robot" << endl << endl;
    displayCommandList();

    string inputtedCommand;

    while(true) {
        cout << "Enter Command: ";
        getline(std::cin >> std::ws, inputtedCommand);

        Commands command = convertStringToCommand(inputtedCommand);

        if (command == EXIT) {
            cout << "Stopping Process..." << endl << endl;
            break;
        }

        if (command == INVALID) {
            cout << "Command not recognized!" << endl << endl;
            continue;
        }

        if (!IsRobotInitialized() && (command != EXIT && command != PLACE)) {
            cout << "Robot has not been placed on the table! Ignoring..." << endl << endl;
            continue;
        }

        switch(command) {
            case PLACE:
                initializeRobot(inputtedCommand);
                break;

            case REPORT:
                reportLocation();
                break;

            default: cout << "Invalid Command!" << endl << endl;
        }
    }
}


void Robot::reportLocation() {
    cout << robotX << "," << robotY << "," << convertDirectionToString(robotDirection) << endl << endl;
}


void Robot::setIsRobotInitialized(bool _isRobotInitialized) {
    isRobotInitialized = _isRobotInitialized;
}


bool Robot::IsRobotInitialized() {
    return isRobotInitialized;
}


void Robot::initializeRobot(string placeCommand) {
    std::stringstream ss(placeCommand);
    string placeCommandFragment;
    std::vector<string> placeCommandVector;

    while(ss >> placeCommandFragment) {
        placeCommandVector.push_back(placeCommandFragment);
    }

    std::istringstream iss(placeCommandVector.at(1));
    std::vector<string> placeValuesVector;

    while (getline(iss, placeCommandFragment, ',')) {
        placeValuesVector.push_back(placeCommandFragment);
    }

    string strInitialX = placeValuesVector.at(0);
    string strInitialY = placeValuesVector.at(1);
    Directions initialDirection = convertStringToDirection(placeValuesVector.at(2));

    if (std::isdigit(strInitialX[0]) && std::isdigit(strInitialY[0]) && (initialDirection != NONE)) {
        int x = std::stoi(strInitialX);
        int y = std::stoi(strInitialY);

        if ((x > TABLE_X || x < 0) && (y > TABLE_Y || y < 0)) {
            cout << "Invalid coordinates!" << endl << endl;
        } else {
            robotX = x;
            robotY = y;
            robotDirection = initialDirection;

            setIsRobotInitialized(true);
        }
    } else {
        cout << "Malformed PLACE command!" << endl << endl;
    }
}
