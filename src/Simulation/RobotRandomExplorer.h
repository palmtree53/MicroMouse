#ifndef CPP_ROBOTRANDOMEXPLORER_H
#define CPP_ROBOTRANDOMEXPLORER_H
#include "Robot.h"

class RobotRandomExplorer: public Robot  {
public:
    RobotRandomExplorer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}
    void nextStep(const Maze& maze) override;
    [[nodiscard]] const Grid<RobotCell> &getGridMap() const override;
};



#endif //CPP_ROBOTRANDOMEXPLORER_H
