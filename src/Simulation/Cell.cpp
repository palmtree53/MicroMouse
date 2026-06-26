//
// Created by aleks on 14.04.2026.
//

#include "Cell.h"

Cell::Cell() {
    walls = {
        {Direction::NORTH, false},
        {Direction::EAST, false},
        {Direction::SOUTH, false},
        {Direction::WEST, false},
        };
}
Cell::Cell(bool north, bool south, bool east, bool west) {
    walls = {
        {Direction::NORTH, north},
        {Direction::EAST, east},
        {Direction::SOUTH, south},
        {Direction::WEST, west},
        };
}


