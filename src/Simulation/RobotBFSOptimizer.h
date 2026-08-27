//
// Created by aleks on 17.07.2026.
//

#ifndef CPP_ROBOTBFSOPTIMIZER_H
#define CPP_ROBOTBFSOPTIMIZER_H
#include "Robot.h"


/**
 * @ingroup SimulationModule
 * @class RobotBFSOptimizer
 * @brief A robot that first explores the entire maze using DFS, then finds the shortest path using BFS.
 *
 * Works in two phases:
 * 1. Explores the whole maze recursively and records every step.
 * 2. Runs BFS on the discovered map to find the optimal path from start to end.
 * Then replays both phases step by step for visualization.
 */
class RobotBFSOptimizer: public Robot {
public:
    /**
     * @brief Creates a BFS optimizer robot at the given location.
     * @param location Starting position.
     * @param mazeWeight Maze width.
     * @param mazeHeight Maze height.
     */
    RobotBFSOptimizer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}

    /**
     * @brief Performs one step of the simulation.
     * On the first call, computes the full exploration and optimal path.
     * On next calls, re-runs the exploration moves, then the optimal path moves.
     * @param maze The maze to solve.
     */
    void nextStep(const Maze& maze) override;

    /**
     * @brief Returns the exploration map or optimal path map depending on current phase.
     * @return The grid map matching the robot's current state.
     */
    const Grid<RobotCell>& getGridMap() const override;


private:
    bool calculated = false;
    void exploreMaze(Location location, const Maze& maze, bool& found);

    bool isEveryThingExplored();

    void optimizePath(Location startLocation, Location endLocation);

    [[nodiscard]] vector<Location> possibleMoves(Location location) const;

    vector<Location> optimalPath;
};



#endif //CPP_ROBOTBFSOPTIMIZER_H
