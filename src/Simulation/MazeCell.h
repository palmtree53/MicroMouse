//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H

#include "AbstractCell.h"


using namespace std;

class MazeCell: public AbstractCell {

public:
    MazeCell() = default;
    MazeCell(const bool north, const bool south, const bool east, const bool west): AbstractCell(north, south, east, west) {}

};



#endif //CPP_CELL_H
