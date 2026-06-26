//
// Created by aleks on 14.06.2026.
//

#ifndef CPP_MAZEVIEW_H
#define CPP_MAZEVIEW_H

#include <string>
#include <vector>
#include <iostream>

#include "../Simulation/Cell.h"
#include "../Simulation/Maze.h"
#include "../Simulation/Location.h"


using namespace std;



class MazeView {
public:
    MazeView(int width=16, int height=16)
        : widthInCells(width), heightInCells(height),
          totalWidth(width * cellWidthSize),
          totalHeight(height * cellHeightSize),
          buffer(height * cellHeightSize, string(width * cellWidthSize, 'e')) {
    }

    void draw(const Maze& state, Location robotLocation);

private:
    int widthInCells;
    int heightInCells;
    int cellWidthSize = 7;
    int cellHeightSize = 3;
    int totalWidth, totalHeight;
    vector<string> buffer;

    void clear();
    void put(int x, int y, char c);
    //x, y w ramach rozmiaru widthInCells*heightInCells
    void putSprite(int x, int y, const vector<string>& sprite);
    static vector<string> writeCell(Cell cell, const bool &containsRobot, const bool &containsTarget);
    void render() const;

};



#endif //CPP_MAZEVIEW_H
