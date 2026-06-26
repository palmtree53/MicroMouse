//
// Created by aleks on 14.04.2026.
//

#include "Location.h"

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