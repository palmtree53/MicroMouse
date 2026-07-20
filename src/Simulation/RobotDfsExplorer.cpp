//
// Created by aleks on 1.07.2026.
//

#include "RobotDfsExplorer.h"
#include <stdexcept>

//to make possible recursive function, the whole path is calculated upfront. the rule of robot not knowing the maze is still respected
void RobotDfsExplorer::nextStep(const Maze& maze) {
    if (!calculated) {
        bool found = false;
        exploreMaze(maze.getStart(), maze, found);
        calculated = true;
    } else {
        if (moves.size() > stepNumber) {
            currentLocation = moves[stepNumber];
            updateExplorationPathMap(currentLocation);
            stepNumber++;
        } else { finished = true; }
    }
}

void RobotDfsExplorer::exploreMaze(Location location, const Maze& maze, bool& found) {

    const MazeCell mazeCell = maze.getGrid().get(location);
    addMove(location);
    updateMap(location, mazeCell.getWalls());
    if (maze.containsGoal(location)) { found = true; return; };
    vector<Location> possibleMoves = maze.possibleMoves(location);

    for (auto& possibleMove: possibleMoves) {
        if (!visitedLocation(possibleMove)) {
            exploreMaze(possibleMove, maze, found);
            if (found) return;
            addMove(location); //write when backs
        }
    }

}

const Grid<RobotCell>& RobotDfsExplorer::getGridMap() const {
    switch (state) {
        case RobotState::EXPLORING: return explorationMap; break;
        case RobotState::OPTIMIZING:
            throw std::invalid_argument("should never happen, fix the inheritancce and polimorphizm");
    }
    throw std::invalid_argument("Unknown RobotState, check implementation");
}