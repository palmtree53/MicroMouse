//
// Created by aleks on 14.04.2026.
//

#include "Maze.h"

#include <iostream>

void Maze::display() {
    for (int y = 0; y < 16; y++) {  //y 1-> -16
        //x 1-> 16
        for (int x = 0; x < 16; x++) { cout<<grid.get(Location(x, y)).drawUpper(); } cout<<endl;
        for (int x = 0; x < 16; x++) { cout<<grid.get(Location(x, y)).drawMiddle(); } cout<<endl;
        for (int x = 0; x < 16; x++) { cout<<grid.get(Location(x, y)).drawDown(); } cout<<endl;
    }
}
