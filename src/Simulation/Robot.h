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
 * Robot generally know the appearance of the maze - it's with and height and position it will be starting at.
 * Depending on implementation, could have memory of where it has been or not.
 * Currently does not have relative directions (f. e. to the left, to the right), always knows the absolute direction - (f. north, south)
 * and doesnt turn around, always has fixed position.
 */
class Robot {

public:
     /**
     * @brief Performs one step of the robot's algorithm.
     * @param possibleMoves the move that step can go to
     * @param containGoal - informs whether the current location contains a goal
     */
    virtual bool nextStep(const vector<Location> &possibleMoves, bool containGoal) = 0;

    /** @brief Returns where the robot currently is. */
    [[nodiscard]] Location getLocation() const;

    /**
     * @brief Returns the grid map build on robots moves in the maze. giving information about the robot's memory.
     * Used mainly to view.
     */
    [[nodiscard]] virtual const Grid<RobotCell>& getGridMap() const;

    /** @brief Returns the full history of moves the robot has made. */
    vector<Location> getMoves();

    /** @brief Returns number of steps. */
     [[nodiscard]] virtual int getStepNumber() const;

    /** @brief Returns number of steps made in optimal path. */
    [[nodiscard]] virtual int getOptimalPathStepNumber() const;

    /** @brief Returns counted number or encountered dead ends in maze. */
     [[nodiscard]] int getDeadEndCount() const;

     virtual ~Robot() = default;


protected:
    /** @brief Checks if the robot has already been in this location. */
    [[nodiscard]] bool visitedLocation(Location location) const;

    /**
     * @brief Creates a robot at the given location with maps sized to the maze.
     * @param start assigns a start of the maze location  and also a current location
     * @param mazeWeight Maze width (columns) (columns) to initialize it's internal map.
     * @param mazeHeight Maze height (rows) to initialize it's internal map.
     */
    explicit Robot(Location start, int mazeWeight, int mazeHeight);

    /**
     * @brief Updates the robot's own map with based on moves now available.
     * Builds the robots view and knowledge about shape of maze and walls. Marks the cell as visited. Needed for optimization.
     */
    void updateMap(Location location, const vector<Location> &possibleMoves);

    /** @brief Saves a move to the given location to the moves history. */
    void addMove(Location location);

    Location currentLocation;
    vector<Location> moves;
    Grid<RobotCell> gridMap;
    Location start;
    Location end;

    int stepNumber = 0;
    int optimaPathStepNumber = 0;
    int deadEndCount = 0;

    RobotState state = RobotState::EXPLORING;
};



#endif //CPP_ROBOT_H
