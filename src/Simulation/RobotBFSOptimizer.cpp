//
// Created by aleks on 17.07.2026.
//

#include "RobotBFSOptimizer.h"

#include <algorithm>
#include <queue>
#include <ranges>
#include <stdexcept>


void RobotBFSOptimizer::nextStep(const Maze& maze) {
    if (!calculated) {
        bool found = false;
        exploreMaze(maze.getStart(), maze, found);
        optimizePath(maze.getStart(), maze.getEnd()); //todo uzyc mapy robota wylacznie
        calculated = true;
    } else {
        if (moves.size() > stepNumber) {
            currentLocation = moves[stepNumber];
            updateExplorationPathMap(currentLocation);
            stepNumber++;
        } else if (stepNumber >= moves.size() && optimaPathStepNumber < optimalPath.size() ) {
            state = RobotState::OPTIMIZING;
            currentLocation = optimalPath[optimaPathStepNumber];
            updateOptimizationPathMap(currentLocation);
            optimaPathStepNumber++;
        }
        else { finished = true; }
    }

}

const Grid<RobotCell>& RobotBFSOptimizer::getGridMap() const {
    switch (state) {
        case RobotState::EXPLORING: return explorationMap;
        case RobotState::OPTIMIZING: return optimalPathMap;
    }
    throw std::invalid_argument("Unknown RobotState, check implementation");
}

void RobotBFSOptimizer::exploreMaze(Location location, const Maze& maze, bool& found) {

    const MazeCell mazeCell = maze.getGrid().get(location);
    addMove(location);
    updateMap(location, mazeCell.getWalls());
    if (isEveryThingExplored()) { found = true; return; };
    vector<Location> possibleMoves = maze.possibleMoves(location);

    for (auto& possibleMove: possibleMoves) {
        if (!visitedLocation(possibleMove)) {
            exploreMaze(possibleMove, maze, found);
            if (found) return;
            addMove(location); //write when backs
        }
    }
    //for now explore everything
}




bool RobotBFSOptimizer::isEveryThingExplored() {
    for (int y = 0; y < gridMap.getHeight(); y++) {
        for (int x = 0; x < gridMap.getWidth(); x++) {
            if (gridMap.get(x, y).getVisited() == false) return false;
        }
    }
    return true;
}

void RobotBFSOptimizer::optimizePath(Location startLocation, Location endLocation) {
    const int rows = gridMap.getHeight();
    const int cols = gridMap.getWidth();

    vector<vector<bool>>     seen(rows, vector<bool>(cols, false));
    vector<vector<Location>> cameFrom(rows, vector<Location>(cols));

    queue<Location> q;
    q.push(startLocation);
    seen[startLocation.y()][startLocation.x()] = true;

    while (!q.empty()) {
        Location current = q.front();
        q.pop();

        if (current == endLocation) break;

        for (const Location& next : possibleMoves(current)) {
            if (seen[next.y()][next.x()]) continue;
            seen[next.y()][next.x()] = true;
            cameFrom[next.y()][next.x()] = current;
            q.push(next);
        }
    }

    vector<Location> path;
    if (!seen[endLocation.y()][endLocation.x()]) optimalPath = path;
    else {
        for (Location at = endLocation; !(at == startLocation); at = cameFrom[at.y()][at.x()]) {
            path.push_back(at);
        }
        path.push_back(startLocation);
        ranges::reverse(path.begin(), path.end());

        optimalPath = path;
    }
}

[[nodiscard]] vector<Location> RobotBFSOptimizer::possibleMoves(Location location) const {
    const RobotCell& cell = gridMap.get(location);
    vector<Location> openLocations;
    for (const auto& [dir, isWall] : cell.getWalls()) {
        if (!isWall) {
            openLocations.push_back(location + dir);
        }
    }
    return openLocations;
}