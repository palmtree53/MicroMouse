//
// Created by aleks on 14.04.2026.
//

#include "Location.h"
#include <stdexcept>


Location::Location(): xValue(0), yValue(0) {};

Location::Location(int x, int y) {
    xValue = x;
    yValue = y;
}
[[nodiscard]] int Location::x() const { return xValue; }
[[nodiscard]] int Location::y() const { return yValue; }

bool Location::operator==(const Location & location) const {
    return this->xValue == location.xValue && this->yValue == location.yValue;
}


Location Location::operator+(const Direction direction) const {
    switch(direction) {
        case Direction::NORTH: return {xValue, yValue - 1};
        case Direction::SOUTH: return {xValue, yValue + 1};
        case Direction::EAST: return {xValue + 1, yValue};
        case Direction::WEST: return {xValue -1, yValue};
    }
    throw std::logic_error("invalid direction");
}

bool Location::operator<(const Location& other) const { //for bfs
    if (yValue != other.yValue) return yValue < other.yValue;
    return xValue < other.xValue;
}
