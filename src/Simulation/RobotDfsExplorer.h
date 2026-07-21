//
// Created by aleks on 1.07.2026.
//

#ifndef CPP_ROBOTDFS_H
#define CPP_ROBOTDFS_H
#include "Robot.h"

//find the way out robot
class RobotDfsExplorer: public Robot {

public:
    RobotDfsExplorer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}
    void nextStep(const Maze& maze) override;
    const Grid<RobotCell>& getGridMap() const override;


private:
    bool calculated = false;
    void exploreMaze(Location location, const Maze& maze, bool& found);

};



#endif //CPP_ROBOTDFS_H
