//
// Created by aleks on 21.07.2026.
//

#include "RobotRandomExplorer.h"
#include <stdexcept>




bool RobotRandomExplorer::nextStep(const vector<Location> &possibleMoves, bool containGoal) {
    if (!containGoal) {
        int randomDirection = rand() % possibleMoves.size();
        Location location = possibleMoves[randomDirection];
        currentLocation = location;
        addMove(currentLocation);
    } else { return true; }
    return false;
}