//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_LOCATION_H
#define CPP_LOCATION_H



class Location {

public:
    Location(int x, int y) {
        this->xValue = x;
        this->yValue = y;
    }
    int x() { return this->xValue; }
    int y() { return this->xValue; }

private:
    int xValue;
    int yValue;
};



#endif //CPP_LOCATION_H
