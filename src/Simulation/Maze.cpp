//
// Created by aleks on 14.04.2026.
//

#include "Maze.h"

Maze::Maze(const Grid<Cell> &grid, const Location start, const Location end) : start(start), end(end), grid(grid) {}
[[nodiscard]] Location Maze::getStart() const { return start; }
[[nodiscard]] Location Maze::getEnd() const { return end; }
[[nodiscard]] Grid<Cell> Maze::getGrid() const { return grid ; }