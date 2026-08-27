//
// Created by aleks on 14.06.2026.
//

#ifndef CPP_MAZEVIEW_H
#define CPP_MAZEVIEW_H

#include <string>

#include "../Simulation/Simulation.h"

/**
 * @ingroup ViewModule
 * @brief Prints the maze to the console.
 *
 * Draws the maze grid cell by cell into an internal character buffer,
 * then prints it to standard output. Supports rendering with or
 * without simulation state. Is used in the simulation state.
 */
class MazeView {
public:
    /**
     * @brief Creates a view for a maze with the given dimensions.
     *
     * @param width  Maze width in cells.
     * @param height Maze height in cells.
     */
    MazeView(int width, int height)
        : widthInCells(width), heightInCells(height),
          totalWidth(width * cellWidthSize),
          totalHeight(height * cellHeightSize),
          buffer(height * cellHeightSize, string(width * cellWidthSize, 'e')) {
    }

    /**
     * @brief Draws the maze with full simulation state.
     *
     * Renders walls, start, end, robot position and visited cells.
     *
     * @param sim The current simulation to read state from.
     */
    void drawMaze(const Simulation& sim);

    /**
     * @brief Draws the maze without simulation state.
     *
     * Renders only walls, start and end markers.
     *
     * @param maze The maze to draw.
     */
    void drawMaze(const Maze& maze);

    // void drawRobotMaze(const Grid<RobotCell>& state, Location currentRobotLocation);


private:
    //todo czy te wartosci są koniecznie - i tak jest przekazana cała symulacja
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
    static vector<string> writeCell(const MazeCell &cell, const bool &containsStart, const bool &containsTarget, const bool &containsRobot = false, bool remembered = false, bool
                                    visited = false);
    void render() const;

    // vector<string> writeRobotCell(const RobotCell& cell, bool isRobotThere);

};



#endif //CPP_MAZEVIEW_H
