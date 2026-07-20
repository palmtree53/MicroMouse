//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_MAZE_H
#define CPP_MAZE_H

#include <set>

#include "MazeCell.h"
#include "Grid.h"

//todo size changes
class Maze {

public:
    Maze(const Grid<MazeCell> &grid, Location start, Location end);
    [[nodiscard]] Location getStart() const;
    [[nodiscard]] Location getEnd() const;
    [[nodiscard]] Grid<MazeCell> getGrid() const;
    [[nodiscard]] bool containsGoal(Location location) const;
    [[nodiscard]] std::vector<Location> possibleMoves(Location location) const;

private:
    Grid<MazeCell> grid;
    Location start;
    Location end;
};



#endif //CPP_MAZE_H
