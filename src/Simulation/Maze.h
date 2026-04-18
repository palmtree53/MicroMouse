//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_MAZE_H
#define CPP_MAZE_H
#include "Cell.h"
#include "Grid.h"

//todo size changes
class Maze {
    public:
    void display();
    void set(Grid<Cell, 1, 1> grid) {
        this -> grid = grid;

    }

private:
    Grid<Cell, 1, 1> grid = {};

};



#endif //CPP_MAZE_H
