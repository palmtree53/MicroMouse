//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_LOCATION_H
#define CPP_LOCATION_H


class Location {

public:
    Location(int x, int y) {
        xValue = x;
        yValue = y;
    }
    [[nodiscard]] int x() const { return xValue; }
    [[nodiscard]] int y() const { return yValue; }

    bool operator==(const Location & location) const {
        return this->xValue == location.xValue && this->yValue == location.yValue;
    };

private:
    int xValue;
    int yValue;


};



#endif //CPP_LOCATION_H
