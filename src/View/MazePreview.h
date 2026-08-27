//
// Created by aleks on 20.07.2026.
//

#ifndef CPP_MAZEPREVIEW_H
#define CPP_MAZEPREVIEW_H
#include "../Simulation/Maze.h"

/**
 * @ingroup ViewModule
 * @class MazePreview
 * @brief View serving the appearance of the maze.
 *
 * Print the maze once and instructions at screen. Is used when in game state MAZE_PREVIEW. Uses basic MazeVIew class.
 */
class MazePreview {
public:
    /**
    * @brief Draws a maze onces.
    * @param maze The maze to draw.
    */
    static void draw(Maze& maze);
};



#endif //CPP_MAZEPREVIEW_H
