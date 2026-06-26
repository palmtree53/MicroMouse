//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

Robot::Robot(const Location location): currentLocation(location) {}

//todo tutaj mozna zamienic na sprawdzenie czy robot sie ruszyl czy utknął -zwróć true-false
void Robot::move() {
    currentLocation = {currentLocation.x() + 1, currentLocation.y()};
}
Location Robot::getLocation() const {
    return currentLocation;
}
