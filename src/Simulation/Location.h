//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_LOCATION_H
#define CPP_LOCATION_H


class Location {

public:
    Location();
    Location(int x, int y);
    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;
    bool operator==(const Location & location) const;

private:
    int xValue;
    int yValue;


};



#endif //CPP_LOCATION_H
