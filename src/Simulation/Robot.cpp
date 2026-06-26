//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

Robot::Robot(const Location location): currentLocation(location) {}

Location Robot::move() {
    return {currentLocation.x() + 1, currentLocation.y()};
}
Location Robot::getLocation() const {
    return currentLocation;
}
