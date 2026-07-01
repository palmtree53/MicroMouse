//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_MAZE_H
#define CPP_MAZE_H

#include <set>
#include <unordered_set>

#include "Cell.h"
#include "Grid.h"
#include "Location.h"

//todo size changes
class Maze {

public:
    Maze(const Grid<Cell> &grid, Location start, Location end);
    [[nodiscard]] Location getStart() const;
    [[nodiscard]] Location getEnd() const;
    [[nodiscard]] Grid<Cell> getGrid() const;
    [[nodiscard]] set<Direction> possibleDirections(Location location) const;

    vector<Location> possibleMoves(Location location) const;

private:
    Grid<Cell> grid;
    Location start;
    Location end;
};



#endif //CPP_MAZE_H
