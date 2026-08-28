//
// Created by aleks on 20.06.2026.
//

#include "Robot.h"

using namespace std;

Robot::Robot(const Location start, int mazeWeight, int mazeHeight):
    start(start), currentLocation(start), gridMap(mazeWeight, mazeHeight) {}//, explorationMap(mazeWeight, mazeHeight), optimalPathMap(mazeWeight, mazeHeight) {}

//todo tutaj mozna zamienic na sprawdzenie czy robot sie ruszyl czy utknął -zwróć true-false
//albo czy skonczyl sie ruszac czy nie - is game ended chyba jest nieprawidlowe -tylko robot wie kiedy skonczyl

Location Robot::getLocation() const {
    return currentLocation;
}

const Grid<RobotCell>& Robot::getGridMap() const {
    return gridMap;
}

vector<Location> Robot::getMoves() { return moves; }

int Robot::getStepNumber() const { return moves.size(); }

int Robot::getOptimalPathStepNumber() const { return optimaPathStepNumber; }

int Robot::getDeadEndCount() const { return deadEndCount; }

void Robot::addMove(const Location location) {
    moves.push_back(location);
}


bool isWall(const Location location, const vector<Location> &possibleMoves, const Direction dir) {
    const Location neighbor = location + dir;
    for (const Location& move : possibleMoves) {
        if (move == neighbor) return false;
    }
    return true;
};


void Robot::updateMap(const Location location, const vector<Location> &possibleMoves) {
    RobotCell& cell = gridMap.get(location);

    cell.setWalls({
        {Direction::NORTH, isWall(location, possibleMoves, Direction::NORTH)},
        {Direction::EAST, isWall(location, possibleMoves, Direction::EAST)},
        {Direction::SOUTH, isWall(location, possibleMoves, Direction::SOUTH)},
        {Direction::WEST, isWall(location, possibleMoves, Direction::WEST)},
        });
    cell.setVisited();
}


bool Robot::visitedLocation(const Location location) const {
    return gridMap.get(location).getVisited();
}
