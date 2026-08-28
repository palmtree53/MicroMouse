//
// Created by aleks on 20.07.2026.
//

#include "MazePreview.h"
#include "MazeView.h"
#include <iostream>

using namespace std;

void MazePreview::draw(Maze& maze) {
    system("cls");
    cout<<endl<<endl<<"MAZE PREVIEW"<<endl<<endl;
    MazeView view(maze.getGrid().getWidth(), maze.getGrid().getHeight());
    view.drawMaze(maze);
    cout<<"TO START A SIMULATION ENTER S"<<endl;
    cout<<"TO LOAD MAZE AGAIN ENTER V"<<endl;
    cout<<"TO GO TO MAIN MENU ENTER M"<<endl;
}