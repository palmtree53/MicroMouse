//
// Created by aleks on 14.04.2026.
//

#include "Maze.h"

Maze::Maze(const Grid<Cell> &grid, const Location start, const Location end) : start(start), end(end), grid(grid) {}
[[nodiscard]] Location Maze::getStart() const { return start; }
[[nodiscard]] Location Maze::getEnd() const { return end; }
[[nodiscard]] Grid<Cell> Maze::getGrid() const { return grid ; }

[[nodiscard]] set<Direction> Maze::possibleDirections(Location location) const {
    auto cell = grid.get(location.x(), location.y());
    set<Direction> openDirections;
    for (const auto& [dir, isWall] : cell.getWalls()) {
        if (!isWall) {
            openDirections.insert(dir);
        }
    }
    return openDirections;
}


[[nodiscard]] vector<Location> Maze::possibleMoves(Location location) const {
    auto cell = grid.get(location.x(), location.y());
    vector<Location> openLocations;
    for (const auto& [dir, isWall] : cell.getWalls()) {
        if (!isWall) {
            openLocations.push_back(location+dir);
        }
    }
    return openLocations;
}


