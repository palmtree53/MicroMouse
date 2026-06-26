//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H
#include <map>
#include <bits/basic_string.h>

#include "Direction.h"

using namespace std;

class Cell {

public:
    Cell();
    Cell(bool north, bool south, bool east, bool west);
    map<Direction, bool> getWalls() { return walls; }

private:
    map<Direction, bool> walls;
};



#endif //CPP_CELL_H
