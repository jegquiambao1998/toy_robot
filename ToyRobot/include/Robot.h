#ifndef ROBOT_H
#define ROBOT_H

#include <string>

#include "Constants.h"

class Robot {
    public:
        Robot();
        virtual ~Robot();

        void displayCommandList();
        void startProcess();
        void reportLocation();

        void setIsRobotInitialized(bool _isRobotInitialized);
        bool IsRobotInitialized();

    protected:

    private:
        void initializeRobot(std::string placeCommand);
        void moveRobot();
        void rotateRobotLeft();
        void rotateRobotRight();

        int robotX;
        int robotY;
        Directions robotDirection;

        bool isRobotInitialized;
};

#endif // ROBOT_H
