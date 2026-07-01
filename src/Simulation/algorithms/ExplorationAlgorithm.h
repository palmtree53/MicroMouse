//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ALGORITHM_H
#define CPP_ALGORITHM_H
#include <vector>

#include "../Location.h"
#include "../Maze.h"
#include "../Robot.h"

using namespace std;

class ExplorationAlgorithm {

public:
    virtual ~ExplorationAlgorithm() = default;

    virtual void exploreMaze(Location currentLocation, const Maze& maze, Robot& robot) = 0;

    bool found = false;

};



#endif //CPP_ALGORITHM_H
