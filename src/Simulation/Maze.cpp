//
// Created by aleks on 14.04.2026.
//

#include "Maze.h"

Maze::Maze(const Grid<MazeCell> &grid, const Location start, const Location end) : start(start), end(end), grid(grid) {}
[[nodiscard]] Location Maze::getStart() const { return start; }
[[nodiscard]] Location Maze::getEnd() const { return end; }
[[nodiscard]] bool Maze::containsGoal(const Location location) const { return location == end; }
[[nodiscard]] Grid<MazeCell> Maze::getGrid() const { return grid ; }


[[nodiscard]] std::vector<Location> Maze::possibleMoves(Location location) const {
    auto cell = grid.get(location.x(), location.y());
    std::vector<Location> openLocations;
    for (const auto& [dir, isWall] : cell.getWalls()) {
        if (!isWall) {
            openLocations.push_back(location+dir);
        }
    }
    return openLocations;
}


