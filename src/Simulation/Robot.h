//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include <set>
#include <vector>

#include "Cell.h"
#include "Direction.h"
#include "Grid.h"
#include "Location.h"
#include "RobotCell.h"

using namespace std;


class Robot {

public:
    explicit Robot(Location location, int mazeWeight, int mazeHeight);
    // void move(const std::set<Direction>& directions);
    [[nodiscard]] Location getLocation() const;
    void addMove(Location location);
    void updateMap(Location location, const Cell& mazeCell);
    [[nodiscard]] bool visitedLocation(Location location) const;

    //tylko na debug
    Grid<RobotCell> getGridMap() {return gridMap;};
    vector<Location> getMoves() {return moves;};

private:
    Location currentLocation;
    // Direction chooseDirectionRandom(const std::set<Direction>& directions);
    // void moveRandom(const std::set<Direction>& directions);
    vector<Location> moves;
    Grid<RobotCell> gridMap;



};



#endif //CPP_ROBOT_H
