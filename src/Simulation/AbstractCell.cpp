//
// Created by aleks on 28.06.2026.
//

#include "AbstractCell.h"

void AbstractCell::setWalls(bool north, bool south, bool east, bool west) {
    walls = {
        {Direction::NORTH, north},
        {Direction::EAST, east},
        {Direction::SOUTH, south},
        {Direction::WEST, west},
        };
    }

void AbstractCell::setWalls(map<Direction, bool> walls){ this->walls = walls; }

AbstractCell::AbstractCell(bool north, bool south, bool east, bool west) {
    setWalls(north, south, east, west);
}