//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_EXPLORATIONALGSIMPLEDFS_H
#define CPP_EXPLORATIONALGSIMPLEDFS_H
#include "ExplorationAlgorithm.h"

#include <iostream>
#include "ExplorationAlgRandom.h"
#include <thread>
#include <chrono>

#include "../../View/MazeView.h"


class ExplorationAlgSimpleDFS: public ExplorationAlgorithm{
public:
    void exploreMaze(Location currentLocation, const Maze& maze, Robot& robot) override;

private:
    MazeView view;

};



#endif //CPP_EXPLORATIONALGSIMPLEDFS_H
