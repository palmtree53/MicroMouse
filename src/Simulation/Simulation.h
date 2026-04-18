//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include "Cell.h"
#include "Maze.h"


class Simulation {

public:
    Maze defaultMaze() {
        Maze maze = Maze();
        Cell table[1][1] = {
            Cell(false, false, false, false),
        };
        maze.set(Grid<Cell, 1, 1>(table));
    }

};



#endif //CPP_SIMULATION_H
