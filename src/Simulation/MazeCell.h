//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H

#include "AbstractCell.h"


using namespace std;

/**
 * @ingroup SimulationModule
 * @class MazeCell
 * @brief A cell in the maze. Inherits wall data from AbstractCell.
 */
class MazeCell: public AbstractCell {

public:
    /** @brief Default constructor. No walls set. */
    MazeCell() = default;

    /**
     * @brief Creates a cell with walls specified for each direction.
     * @param north Wall on north.
     * @param south Wall on south.
     * @param east Wall on the east.
     * @param west Wall on the west.
     */
    MazeCell(const bool north, const bool south, const bool east, const bool west): AbstractCell(north, south, east, west) {}

};



#endif //CPP_CELL_H
