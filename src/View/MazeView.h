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
    MazeView(/*int width=16*8 , int height=16*3*/)
    : w(/*width*/ defaultWidth*defaultWidthSize),
    h(/*height*/ defaultHeight*defaultHeightSize),
    buffer(defaultHeight*defaultHeightSize/*height*/, string(defaultWidth*defaultWidthSize /*width*/, 'e')) {}

    void draw(const Maze& state, Location robotLocation);

private:
    int defaultWidth = 16;
    int defaultHeight = 16;
    int defaultWidthSize = 7;
    int defaultHeightSize = 3;
    //todo poprzenosic do źródła
    int w, h;
    vector<string> buffer;

    void clear();
    void put(int x, int y, char c);
    //x, y w ramach rozmiaru 16*16
    void putSprite(int x, int y, const vector<string>& sprite);
    static vector<string> writeCell(Cell cell, const bool &containsRobot, const bool &containsTarget);
    void render() const;

};



#endif //CPP_MAZEVIEW_H
