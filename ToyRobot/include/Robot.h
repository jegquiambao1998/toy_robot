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
        void initializeRobot(int initialX, int initialY, Directions direction);

        int x;
        int y;
        Directions direction;

        bool isRobotInitialized;
};

#endif // ROBOT_H
