//
// Created by aleks on 17.07.2026.
//

#ifndef CPP_ROBOTBFSOPTIMIZER_H
#define CPP_ROBOTBFSOPTIMIZER_H
#include "Robot.h"


class RobotBFSOptimizer: public Robot {
public:
    RobotBFSOptimizer(Location location, int mazeWeight, int mazeHeight) : Robot(location, mazeWeight, mazeHeight) {}
    void nextStep(const Maze& maze) override;
    const Grid<RobotCell>& getGridMap() const override;


private:
    bool calculated = false;
    void exploreMaze(Location location, const Maze& maze, bool& found);

    bool isEveryThingExplored();

    void optimizePath(Location startLocation, Location endLocation);

    [[nodiscard]] vector<Location> possibleMoves(Location location) const;

    vector<Location> optimalPath;
};



#endif //CPP_ROBOTBFSOPTIMIZER_H
