//
// Created by aleks on 28.06.2026.
//

#include "ExplorationAlgSimpleDFS.h"


void ExplorationAlgSimpleDFS::exploreMaze(Location currentLocation, const Maze& maze, Robot& robot) {

    const Cell mazeCell = maze.getGrid().get(currentLocation);
    robot.addMove(currentLocation);
    robot.updateMap(currentLocation, mazeCell);
    if (currentLocation == maze.getEnd()) { found = true; return; };
    vector<Location> possibleMoves = maze.possibleMoves(currentLocation);

    cout<<endl<<endl;
    view.drawRobotMaze(robot.getGridMap(), currentLocation); // debug only
    // cout<<"debug ExplorationAlgRandom::exploreMaze robot location: ("<<currentLocation.x()<<","<<currentLocation.y()<<")"<<endl;
    // cout<<"possible moves"<<endl;
    // for (auto move: possibleMoves) {
    //     cout<<move.x()<<","<<move.y()<<endl;
    // }
    std::this_thread::sleep_for(100ms);


    for (auto& possibleMove: possibleMoves) {
        if (!robot.visitedLocation(possibleMove)) {
            exploreMaze(possibleMove, maze, robot);
            if (found) return;
            robot.addMove(currentLocation); //write when backs
        }
    }

}