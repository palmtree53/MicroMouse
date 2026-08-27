//
// Created by aleks on 14.04.2026.
//
#pragma once

#include <vector>

#include "Location.h"

#ifndef CPP_GRID_H
#define CPP_GRID_H


/**
 * @ingroup SimulationModule
 * @class Grid
 * @brief A generic 2D grid that stores elements of any type. Used for maze cells, robot maps..
 * @tparam T Type of element stored in each cell.
 */
template<typename T> class Grid {

public:
    /**
     * @brief Creates an empty grid filled with default values.
     * @param width
     * @param height
     */
    Grid(int width, int height) :width(width), height(height), cells(height, std::vector<T>(width, T())) {}

    /**
     * @brief Creates a grid from an existing 2D vector.
     * @param v 2D vector to use as the grid data.
     */
    explicit Grid(std::vector<std::vector<T>> v) : width(calculateWidth(v)), height(calculateHeight(v)), cells(v) {}

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }

    /**
     * @brief Gets a cell by x, y coordinates. Mutable version.
     */
    T& get(int x, int y) {return cells[y][x];}

    /**
     * @brief Gets a cell by x, y coordinates. Read-only version.
     */
    T get(int x, int y) const {return cells[y][x];}

    /**
     * @brief Gets a cell by Location. Mutable version.
     */
    T& get(const Location location) {return cells[location.y()][location.x()];}

    /**
     * @brief Gets a cell by Location. Read-only version.
     */
    T get(const Location location) const {return cells[location.y()][location.x()];}

private:
    int width, height;
    std::vector<std::vector<T>> cells;

    int calculateWidth(const std::vector<std::vector<T>>& v) {
        return v.empty() ? 0 : static_cast<int>(v[0].size());   //todo
    }
    int calculateHeight(const std::vector<std::vector<T>>& v) {
        return static_cast<int>(v.size());
    }
};



#endif //CPP_GRID_H
