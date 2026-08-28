//
// Created by aleks on 17.07.2026.
//

#ifndef CPP_ROBOTBFSOPTIMIZERNEW_H
#define CPP_ROBOTBFSOPTIMIZERNEW_H
#include "Robot.h"
#include <stack>


/**
 * @ingroup SimulationModule
 * @class RobotBFSOptimizerNew
 * @brief A robot that first explores the entire maze using DFS, then finds the shortest path using BFS.
 */
class RobotBFSOptimizerNew: public Robot {
public:
    /**
     * @brief Creates a BFS optimizer robot at the given location.
     * @param start Starting position.
     * @param mazeWeight Maze width.
     * @param mazeHeight Maze height.
     */
    RobotBFSOptimizerNew(Location start, int mazeWeight, int mazeHeight) : Robot(start, mazeWeight, mazeHeight) {}

    /**
     * @brief Performs one step of the simulation, first exploration, then optimal path.
     * Explores Maze first, until it finishes with everything explored, then comes back to the staart and calculates optimal Path.
     * On next calls, moves re-runnig previously calculated optimal path from start to finish.
     * @param possibleMoves calculated moved that are possible to go to.
     * @param containGoal an information, whether current robot location contains a Maze goal.
     */
    bool nextStep(const vector<Location> &possibleMoves, bool containGoal) override;

private:
    bool calculated = false;

    bool stepThroughExploration(const vector<Location> &possibleMoves, bool containGoal);

    bool stepThroughOptimalPath();

    void optimizePath(Location startLocation, Location endLocation);

    [[nodiscard]] vector<Location> possibleMoves(Location location) const;

    int getStepNumber() const;

    [[nodiscard]] int getOptimalPathStepNumber() const override;

    vector<Location> optimalPath;

    std::stack<Location> explorationStack;
    int optimalPathStepNumber = 0;
    int explorationStepNumber = 0;
};



#endif //CPP_ROBOTBFSOPTIMIZERNEW_H
