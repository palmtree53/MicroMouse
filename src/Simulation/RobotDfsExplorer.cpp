//
// Created by aleks on 1.07.2026.
//

#include "RobotDfsExplorer.h"
#include <stdexcept>

bool RobotDfsExplorer::nextStep(const vector<Location> &possibleMoves, const bool containGoal) {
    bool explorationResult = stepThroughExploration(possibleMoves, containGoal);
    if (explorationResult == true) { return true; }
    return false;
}

bool RobotDfsExplorer::stepThroughExploration(const vector<Location> &possibleMoves, const bool containGoal) {

    if (!visitedLocation(currentLocation)) {
        addMove(currentLocation);
        explorationStack.push(currentLocation);
        updateMap(currentLocation, possibleMoves);
    }
    if (containGoal) {
        end = currentLocation;
        return true;
    }

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