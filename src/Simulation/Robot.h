//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include "Location.h"


class Robot {

public:
    Robot() = default;
    //zakladajac z robot nie wie w jakiej komorce jest
    Location move(Location currentLocation) {
        return {currentLocation.x() + 1, currentLocation.y()};
    }
};



#endif //CPP_ROBOT_H
