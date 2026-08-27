//
// Created by aleks on 1.07.2026.
//

#ifndef CPP_ROBOTDFS_H
#define CPP_ROBOTDFS_H
#include "Robot.h"

/**
 * @ingroup SimulationModule
 * @class RobotDfsExplorer
 * @brief A robot that uses DFS (depth-first search) to find the way out of the maze.
 *
 * Computes the full path recursively on the first step, then replays it one move at a time.
 * Does not optimize — just finds the exit and stops.
 */
class RobotDfsExplorer: public Robot {

public:
    /**
     * @brief Creates a DFS explorer robot at the given location.
     * @param location Starting position.
     * @param mazeWeight Maze width.
     * @param mazeHeight Maze height.
     */
    RobotDfsExplorer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}

    /**
     * @brief Performs one step of the simulation.
     * First call runs the full DFS recursively. After that, replays recorded moves one by one.
     * @param maze The maze to explore.
     */
    void nextStep(const Maze& maze) override;

    /**
     * @brief Returns the exploration map. Throws if called in OPTIMIZING state since this robot never optimizes.
     */
    const Grid<RobotCell>& getGridMap() const override;


private:
    bool calculated = false;

    /**
     * @brief Recursive DFS exploration. Stops when the goal is found.
     * Records backing steps too so the path can be replayed fully.
     */
    void exploreMaze(Location location, const Maze& maze, bool& found);

};



#endif //CPP_ROBOTDFS_H
