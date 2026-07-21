//
// Created by aleks on 21.07.2026.
//

#include "RobotRandomExplorer.h"
#include <stdexcept>


const Grid<RobotCell>& RobotRandomExplorer::getGridMap() const {
    switch (state) {
        case RobotState::EXPLORING: return explorationMap;
        case RobotState::OPTIMIZING:
            throw std::invalid_argument("should never happen, fix the inheritancce and polimorphizm");
    }
    throw std::invalid_argument("Unknown RobotState, check implementation");
}

void RobotRandomExplorer::nextStep(const Maze& maze) {
    if (!maze.containsGoal(currentLocation)) {
        vector<Location> possibleMoves = maze.possibleMoves(currentLocation);
        int randomDirection = rand() % possibleMoves.size();
        Location location = possibleMoves[randomDirection];
        currentLocation = location;
        addMove(currentLocation);
    } else { finished = true; }
}