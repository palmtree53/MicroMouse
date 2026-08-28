//
// Created by aleks on 1.07.2026.
//

#ifndef CPP_ROBOTDFS_H
#define CPP_ROBOTDFS_H
#include "Robot.h"
#include <stack>

/**
 * @ingroup SimulationModule
 * @class RobotDfsExplorer
 * @brief A robot that uses DFS (depth-first search) to find the goal in the maze.
 * Works iteratively with a stack and finishes when goal is reached.
 */
class RobotDfsExplorer: public Robot {

public:
    /**
     * @brief Creates a DFS explorer robot at the given location.
     * @param location Starting position.
     * @param mazeWeight Maze width.
     * @param mazeHeight Maze height.
     */
    RobotDfsExplorer(const Location location, const int mazeWeight, const int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}

    /**
     * @brief Performs one step of the simulation.
     * @param possibleMoves
     * @param containGoal
     */
    bool nextStep(const vector<Location> &possibleMoves, bool containGoal)  override;

private:
    /**
     * @brief Iterative DFS exploration. Stops when the goal is found.
     */
    bool stepThroughExploration(const vector<Location> &possibleMoves, bool containGoal);

    std::stack<Location> explorationStack;
};



#endif //CPP_ROBOTDFS_H
