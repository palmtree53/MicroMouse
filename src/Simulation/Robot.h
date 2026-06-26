//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include "Location.h"


class Robot {

public:
    explicit Robot(Location location);
    Location move();
    [[nodiscard]] Location getLocation() const;

private:
    Location currentLocation;
};



#endif //CPP_ROBOT_H
