//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_MAZE_H
#define CPP_MAZE_H

#include <set>

#include "MazeCell.h"
#include "Grid.h"

/**
 * @ingroup SimulationModule
 * @class Maze
 * @brief Represents the maze structure — stores the grid of cells, start and end locations.
 * Keeps a function to calculate which moves are possible from given cell.
 */
class Maze {

public:
    /**
     * @brief Creates a maze from a grid and start, end positions.
     * @param grid Grid of MazeCells defining the walls.
     * @param start The start of the maze, where robot starts.
     * @param end The goal, end of the maze.
     */
    Maze(const Grid<MazeCell> &grid, Location start, Location end);

    [[nodiscard]] Location getStart() const;
    [[nodiscard]] Location getEnd() const;
    [[nodiscard]] Grid<MazeCell> getGrid() const;

    /**
     * @brief Checks if the given location is the goal (end of maze).
     * @param location Location to check.
     * @return True if this is the finish.
     */
    [[nodiscard]] bool containsGoal(Location location) const;

    /**
     * @brief Returns all locations available from the given position.
     * @param location Current position to check from.
     * @return List of neighbors locations that can be moved to.
     */
    [[nodiscard]] std::vector<Location> possibleMoves(Location location) const;

private:
    Grid<MazeCell> grid;
    Location start;
    Location end;
};



#endif //CPP_MAZE_H
