//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include <set>

#include "Direction.h"
#include "Location.h"


class Robot {

public:
    explicit Robot(Location location);
    void move(const std::set<Direction>& directions);
    [[nodiscard]] Location getLocation() const;

private:
    Location currentLocation;
    Direction chooseDirection(const std::set<Direction>& directions);
};



#endif //CPP_ROBOT_H
