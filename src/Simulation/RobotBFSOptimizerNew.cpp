//
// Created by aleks on 17.07.2026.
//

#include "RobotBFSOptimizerNew.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <ranges>

#include "../View/MazeView.h"


bool RobotBFSOptimizerNew::nextStep(const vector<Location> &possibleMoves, const bool containGoal) {
    if (!calculated) {
        bool explorationResult = stepThroughExploration(possibleMoves, containGoal);
        if (explorationResult == true) {
            optimizePath(start, end);
            calculated = true;
        }
    } else {
        if (stepThroughOptimalPath() == true) return true;
    }
    return false;
}


bool RobotBFSOptimizerNew::stepThroughExploration(const vector<Location> &possibleMoves, const bool containGoal) {

    explorationStepNumber++;
    if (!visitedLocation(currentLocation)) {
        addMove(currentLocation);
        explorationStack.push(currentLocation);
        updateMap(currentLocation, possibleMoves);
    }
    if (containGoal) { end = currentLocation; }

    for (auto& possibleMove: possibleMoves) {
        if (!visitedLocation(possibleMove)) {
            currentLocation = possibleMove;
            return false;
        }
    }
    if (possibleMoves.size() == 1) { deadEndCount++; }


    explorationStack.pop();
    if (!explorationStack.empty()) {
        const auto move = explorationStack.top();
        currentLocation = move;
        addMove(move);
        return false;
    }
    return true;
}


bool RobotBFSOptimizerNew::stepThroughOptimalPath() {

    //if everythings valid, it starts with current location = start
    addMove(currentLocation);
    if (currentLocation == end) {
        return true;
    }
    optimalPathStepNumber++;
    currentLocation = optimalPath[optimalPathStepNumber];
    return false;
}




void RobotBFSOptimizerNew::optimizePath(Location startLocation, Location endLocation) {
    // cout<<"start optimising."<<endl;
    // MazeView view(gridMap.getWidth(), gridMap.getHeight());
    // view.drawMaze(gridMap);

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
            if (seen.at(next.y()).at(next.x())) continue;
            seen.at(next.y()).at(next.x()) = true;
            cameFrom.at(next.y()).at(next.x()) = current;
            q.push(next);
        }
    }

    vector<Location> path;
    if (!seen.at(endLocation.y()).at(endLocation.x())) optimalPath = path;
    else {
        for (Location at = endLocation; !(at == startLocation); at = cameFrom[at.y()][at.x()]) {
            path.push_back(at);
        }
        path.push_back(startLocation);
        ranges::reverse(path.begin(), path.end());

        optimalPath = path;
    }
    // cout<<"ended optimising."<<endl;
}

[[nodiscard]] vector<Location> RobotBFSOptimizerNew::possibleMoves(Location location) const {
    const RobotCell& cell = gridMap.get(location);
    vector<Location> openLocations;
    for (const auto& [dir, isWall] : cell.getWalls()) {
        if (!isWall) {
            openLocations.push_back(location + dir);
        }
    }
    return openLocations;
}

int RobotBFSOptimizerNew::getStepNumber() const { return explorationStepNumber; }

int RobotBFSOptimizerNew::getOptimalPathStepNumber() const { return optimalPathStepNumber; }
