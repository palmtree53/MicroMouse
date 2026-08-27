#ifndef CPP_ROBOTRANDOMEXPLORER_H
#define CPP_ROBOTRANDOMEXPLORER_H
#include "Robot.h"

/**
 * @ingroup SimulationModule
 * @class RobotRandomExplorer
 * @brief A robot that picks a random direction each step. Keeps no algorithm, can look for goal forever.
 *
 * Added mostly to have a additional type for variety. Unlike DFS and BFS robots,
 * this one has no strategy — it just moves randomly until it stumbles on exit.
 * Does not optimize.
 */
class RobotRandomExplorer: public Robot  {
public:
    /**
     * @brief Creates a random explorer robot at the given location.
     * @param location Starting position.
     * @param mazeWeight Maze width.
     * @param mazeHeight Maze height.
     */
    RobotRandomExplorer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}

    /**
     * @brief Picks a random available move and goes there. Finishes when it reaches the goal.
     * @param maze The maze.
     */
    void nextStep(const Maze& maze) override;

    /**
     * @brief Returns the exploration map. Throws if called in OPTIMIZING state since this robot never optimizes.
     */
    [[nodiscard]] const Grid<RobotCell> &getGridMap() const override;
};


#endif //CPP_ROBOTRANDOMEXPLORER_H
