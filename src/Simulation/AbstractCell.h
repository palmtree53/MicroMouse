//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ABSTRACTCELL_H
#define CPP_ABSTRACTCELL_H

#include <map>

#include "Direction.h"


/**
 * @ingroup SimulationModule
 * @class AbstractCell
 * @brief Base class for maze cells. Stores wall configuration for four directions.
 */
class AbstractCell {
public:
    virtual ~AbstractCell() = default;

    /**
     * @brief Returns a copy of the wall map.
     * @return Map of directions to wall presence (true = wall exists).
     */
    [[nodiscard]] std::map<Direction, bool> getWalls() const { return walls; }

    /**
     * @brief Sets walls for four directions individually.
     * @param north Wall on the north.
     * @param south Wall on the south.
     * @param east Wall on the east.
     * @param west Wall on the west.
     */
    void setWalls(bool north, bool south, bool east, bool west);

    /**
     * @brief Sets walls from an existing map.
     * @param walls Map of directions to wall existence.
     */
    void setWalls(std::map<Direction, bool> walls);

protected:
    /** @brief Default constructor. Initializes with an empty walls. */
    AbstractCell(): walls({}) {}

    /**
     * @brief Constructs a cell with walls set for all four directions.
     * @param north Wall on the north.
     * @param south Wall on the south.
     * @param east Wall on the east.
     * @param west Wall on the west.
     */
    AbstractCell(bool north, bool south, bool east, bool west);

    std::map<Direction, bool> walls; ///< Map of walls for each direction.
};
#endif //CPP_ABSTRACTCELL_H
