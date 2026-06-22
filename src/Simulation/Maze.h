//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_MAZE_H
#define CPP_MAZE_H
#include "Cell.h"
#include "Grid.h"
#include "Location.h"

//todo size changes
class Maze {

public:
    Maze(const Grid<Cell, 16, 16> &grid, const Location start, const Location end) : start(start), end(end), grid(grid) {};

    [[nodiscard]] Location getStart() const { return start; }
    [[nodiscard]] Location getEnd() const { return end; }
    [[nodiscard]] Grid<Cell, 16, 16> getGrid() const { return grid ; }


private:
    Grid<Cell, 16, 16> grid;
    Location start;
    Location end;

};



#endif //CPP_MAZE_H
