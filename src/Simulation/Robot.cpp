//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

using namespace std;

Robot::Robot(const Location location, int mazeWeight, int mazeHeight): currentLocation(location), gridMap(mazeWeight, mazeHeight), explorationMap(mazeWeight, mazeHeight), optimalPathMap(mazeWeight, mazeHeight) {}

//todo tutaj mozna zamienic na sprawdzenie czy robot sie ruszyl czy utknął -zwróć true-false
//albo czy skonczyl sie ruszac czy nie - is game ended chyba jest nieprawidlowe -tylko robot wie kiedy skonczyl

Location Robot::getLocation() const {
    return currentLocation;
}

void Robot::addMove(const Location location) {
    moves.push_back(location);
}

//mutowalny get gridMap.get(location) - do zmiany
void Robot::updateMap(const Location location, const map<Direction, bool>& walls) {
    RobotCell& cell = gridMap.get(location);
    cell.setWalls(walls);
    cell.setVisited();
}

void Robot::updateExplorationPathMap(const Location location) {
    RobotCell& cell = explorationMap.get(location);
    cell.setVisited();
}


void Robot::updateOptimizationPathMap(const Location location) {// todo jak to rozwiązać
    RobotCell& cell = optimalPathMap.get(location);
    cell.setVisited();
}

bool Robot::visitedLocation(const Location location) const {
    return gridMap.get(location).getVisited();
}

bool Robot::isFinished() const {
    return finished;
}
