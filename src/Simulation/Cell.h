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
    Cell() {
        walls = {
        {Direction::NORTH, true},
        {Direction::EAST, false},
        {Direction::SOUTH, true},
        {Direction::WEST, false},
        };
    }
    Cell(bool north, bool south, bool east, bool west) {
        walls = {
            {Direction::NORTH, north},
            {Direction::EAST, east},
            {Direction::SOUTH, south},
            {Direction::WEST, west},
            };
    }

    map<Direction, bool> walls;
};



#endif //CPP_CELL_H
