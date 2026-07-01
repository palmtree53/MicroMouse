//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_EXPLORATIONALGRANDOM_H
#define CPP_EXPLORATIONALGRANDOM_H
#include "ExplorationAlgorithm.h"
#include <iostream>

#include "../../View/MazeView.h"


class ExplorationAlgRandom: public ExplorationAlgorithm {

public:
    void exploreMaze(Location currentLocation, const Maze& maze, Robot& robot) override;

private:
    MazeView view;

};



#endif //CPP_EXPLORATIONALGRANDOM_H
