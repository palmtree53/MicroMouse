//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H

#include "Maze.h"
#include "RobotCell.h"
#include "RobotState.h"

using namespace std;


/**
 * @ingroup SimulationModule
 * @class Robot
 * @brief Base class for all robots. Handles movement, tracking visited cells, and storing maps.
 * Each subclass implements its own exploration strategy via nextStep().
 * Currently does not have relative directions (f. e. to the left, to the right), always knows the absolute direction - (f. north, south)
 */
class Robot {

public:
    virtual ~Robot() = default;

    /** @brief Returns where the robot currently is. */
    [[nodiscard]] Location getLocation() const;

    /** @brief Saves a move to the given location to the moves history. */
    void addMove(Location location);

    /**
     * @brief Updates the robot's own map with wall info at the given location.
     * Also marks the cell as visited.
     */
    void updateMap(Location location, const map<Direction, bool>& walls);

    /** @brief Marks a cell on the exploration path map as visited. */
    void updateExplorationPathMap(Location location);

    /** @brief Marks a cell on the optimal path map as visited. */
    void updateOptimizationPathMap(Location location);

    /** @brief Checks if the robot has already been in this location. */
    [[nodiscard]] bool visitedLocation(Location location) const;

    /**
     * @brief Returns the grid map giving information about the robot's current state.
     * Each subclass decides which map to return (exploration or optimal path).
     */
    virtual const Grid<RobotCell>& getGridMap() const = 0;

    /** @brief Returns the full list of moves the robot has made. */
    vector<Location> getMoves() {return moves;}

    /**
     * @brief Performs one step of the robot's algorithm.
     * Each subclass implements difrent logic here.
     * @param maze The maze to navigate.
     */
    virtual void nextStep(const Maze& maze) = 0;

    /** @brief Checks if the robot is done with its task. */
    [[nodiscard]] bool isFinished() const;

    [[nodiscard]] int getStepNumber() const { return stepNumber; }
    [[nodiscard]] int getOptimalPathStepNumber() const { return optimaPathStepNumber; }
    [[nodiscard]] int getDeadEndCount() const { return deadEndCount; }

protected:
    /**
     * @brief Creates a robot at the given location with maps sized to the maze.
     * @param location Starting position.
     * @param mazeWeight Maze width (columns).
     * @param mazeHeight Maze height (rows).
     */
    explicit Robot(Location location, int mazeWeight, int mazeHeight);

    Location currentLocation;
    vector<Location> moves;
    Grid<RobotCell> gridMap;
    Grid<RobotCell> explorationMap;
    Grid<RobotCell> optimalPathMap;
    bool finished = false;

    int stepNumber = 0;
    int optimaPathStepNumber = 0;
    int deadEndCount = 0;

    RobotState state = RobotState::EXPLORING;
};



#endif //CPP_ROBOT_H
