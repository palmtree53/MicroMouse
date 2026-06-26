//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

#include <array>
#include <set>

#include "Direction.h"

using namespace std;

Robot::Robot(const Location location): currentLocation(location) {}

//todo tutaj mozna zamienic na sprawdzenie czy robot sie ruszyl czy utknął -zwróć true-false
//albo czy skonczyl sie ruszac czy nie - is game ended chyba jest nieprawidlowe -tylko robot wie kiedy skonczyl

void Robot::move(const set<Direction>& directions) {
    switch(auto direction = chooseDirection(directions)) {
        case Direction::NORTH: currentLocation = {currentLocation.x(), currentLocation.y() - 1}; break;
        case Direction::SOUTH: currentLocation = {currentLocation.x(), currentLocation.y() + 1}; break;
        case Direction::EAST: currentLocation = {currentLocation.x() + 1, currentLocation.y()}; break;
        case Direction::WEST: currentLocation = {currentLocation.x() - 1, currentLocation.y()}; break;
    }
}
Location Robot::getLocation() const {
    return currentLocation;
}

Direction Robot::chooseDirection(const set<Direction>& directions) {
    //napisac przynajmniej jeden algorytm eksploracji
    return *directions.begin();
}
