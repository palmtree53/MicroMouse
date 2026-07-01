//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

#include <array>
#include <set>

#include "Cell.h"
#include "Direction.h"

using namespace std;

Robot::Robot(const Location location, int mazeWeight, int mazeHeight): currentLocation(location), gridMap(mazeWeight, mazeHeight) {}

//todo tutaj mozna zamienic na sprawdzenie czy robot sie ruszyl czy utknął -zwróć true-false
//albo czy skonczyl sie ruszac czy nie - is game ended chyba jest nieprawidlowe -tylko robot wie kiedy skonczyl

// void Robot::move(const set<Direction>& directions) {
//     this->moveRandom(directions);
// }
//
// void Robot::moveRandom(const set<Direction>& directions) {
//     switch(chooseDirectionRandom(directions)) {
//         case Direction::NORTH: currentLocation = {currentLocation.x(), currentLocation.y() - 1}; break;
//         case Direction::SOUTH: currentLocation = {currentLocation.x(), currentLocation.y() + 1}; break;
//         case Direction::EAST: currentLocation = {currentLocation.x() + 1, currentLocation.y()}; break;
//         case Direction::WEST: currentLocation = {currentLocation.x() - 1, currentLocation.y()}; break;
//     }
// }


Location Robot::getLocation() const {
    return currentLocation;
}

void Robot::addMove(const Location location) {
    moves.push_back(location);
}

//mutowalny get gridMap.get(location) - do zmiany
void Robot::updateMap(const Location location, const Cell& mazeCell) {  //todo zamienicna walls
    RobotCell& cell = gridMap.get(location);   // ONE reference to the real stored cell
    cell.setWalls(mazeCell.getWalls());
    cell.setVisited();
}

bool Robot::visitedLocation(const Location location) const {
    return gridMap.get(location).getVisited();
}

// Direction Robot::chooseDirectionRandom(const set<Direction>& directions) {
//     //napisac przynajmniej jeden algorytm eksploracji
//     // return *directions.begin();
//     return directions.contains(Direction::SOUTH) ? Direction::SOUTH :
//             directions.contains(Direction::EAST) ? Direction::EAST :
//             directions.contains(Direction::WEST) ? Direction::WEST :
//             directions.contains(Direction::NORTH) ? Direction::NORTH: Direction::SOUTH;
// }
