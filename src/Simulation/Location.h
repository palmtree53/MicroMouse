//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_LOCATION_H
#define CPP_LOCATION_H
#include "Direction.h"


/**
 * @ingroup SimulationModule
 * @class Location
 * @brief Represents a position on the grid with x and y coordinates.
 * Supports comparison and moving in a direction.
 */
class Location {

public:
    /** @brief Default constructor. Sets position to (0, 0). */
    Location();

    /**
     * @brief Creates a location at given coordinates.
     * @param x Column.
     * @param y Row.
     */
    Location(int x, int y);

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;

    /** @brief Checks if two locations are the same spot. */
    bool operator==(const Location & location) const;

    /**
     * @brief Returns a new location shifted one step in the given direction.
     * Does not modify the original.
     */
    Location operator+(Direction direction) const;

    /** @brief Comparison for use in ordered containers like std::set and std::map. */
    bool operator<(const Location& other) const;

private:
    int xValue;
    int yValue;
};



#endif //CPP_LOCATION_H
