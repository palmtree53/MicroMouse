//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H
#include <map>
#include <bits/basic_string.h>

#include "AbstractCell.h"
#include "Direction.h"

using namespace std;

class Cell: public AbstractCell {

public:
    Cell() {} //for nlohmann-json
    Cell(bool north, bool south, bool east, bool west): AbstractCell(north, south, east, west) {}

};



#endif //CPP_CELL_H
