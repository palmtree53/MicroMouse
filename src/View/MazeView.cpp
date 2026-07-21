//
// Created by aleks on 14.06.2026.
//

#include "MazeView.h"

#include <iostream>

using namespace std;

//todo robot location and destination location - in cell or separate
void MazeView::drawMaze(const Simulation& sim) {
    // void draw(const GameState& state) {
    clear();
    // drawBorder();

    for (int rowNumber = 0; rowNumber < heightInCells; ++rowNumber) //y
        for (int colNumber = 0; colNumber < widthInCells; ++colNumber) //x
        {
            MazeCell tempCell = sim.getMaze().getGrid().get(colNumber, rowNumber);
            putSprite(colNumber, rowNumber, writeCell(
                          tempCell,
                          sim.getMaze().getStart().x() == colNumber && sim.getMaze().getStart().y() == rowNumber,
                          sim.getMaze().getEnd().x() == colNumber && sim.getMaze().getEnd().y() == rowNumber,
                          sim.getRobot()->getLocation().x() == colNumber && sim.getRobot()->getLocation().y() == rowNumber,
                          sim.getRobot()->getGridMap().get(colNumber, rowNumber).getVisited()
                      )
            );
        }

    // drawHUD(state);
    render();
}

void MazeView::drawMaze(const Maze& maze) {
    clear();

    for (int rowNumber = 0; rowNumber < heightInCells; ++rowNumber) //y
        for (int colNumber = 0; colNumber < widthInCells; ++colNumber) //x
        {
            MazeCell tempCell = maze.getGrid().get(colNumber, rowNumber);
            putSprite(colNumber, rowNumber, writeCell(
                          tempCell,
                          maze.getStart().x() == colNumber && maze.getStart().y() == rowNumber,
                          maze.getEnd().x() == colNumber && maze.getEnd().y() == rowNumber
                      )
            );
        }

    render();
}

void MazeView::clear() {
    for (auto& row : buffer)
        row.assign(totalWidth, 'e');
}

void MazeView::put(int x, int y, char c) {
    if (x >= 0 && x < totalWidth && y >= 0 && y < totalHeight)
        buffer[y][x] = c;
}

void MazeView::putSprite(int x, int y, const vector<string>& sprite) {
    for (int row = 0; row < static_cast<int>(sprite.size()); ++row)
        for (int col = 0; col < static_cast<int>(sprite[row].size()); ++col)
            // if (sprite[row][col] != ' ')   // treat space as transparent
                put(cellWidthSize*x + col, cellHeightSize*y + row, sprite[row][col]);
}

vector<string> MazeView::writeCell(const MazeCell& cell, const bool &containsStart, const bool &containsTarget, const bool &containsRobot, const bool remembered, const bool visited) {
    //todo visited kiedy nie jest zapamietany, remebered kiedy zapisany na mapie
    return {
        cell.getWalls()[Direction::NORTH] == true ? "'-----'" : "'     '",
        string(cell.getWalls()[Direction::WEST] == true ? "|" : " ")
        + " "
        + string(
            containsRobot && containsTarget && containsStart ? "SRF"  :
            containsTarget && containsStart ? "S?F"  :
            containsRobot && containsTarget ? "RRF"  :
            containsRobot && containsStart ? "RRS"  :
            containsStart && remembered ? " -S" :
            // containsStart && visited ? " .S" :
            containsStart ? "  S" :
            containsTarget && remembered ? " -F" :
            // containsTarget && visited ? " .F" :
            containsTarget ? "  F" :
            containsRobot ? "RR " :
            remembered ? " - " :
            // visited ? " . " :
            "   "
            )
        + " "
        + (cell.getWalls()[Direction::EAST] == true ? "|" : " "),
        cell.getWalls()[Direction::SOUTH] == true ? ",_____," : ",     ,"
    };
}

void MazeView::render() const {
    // cout << "\033[H";
    for (const auto& row : buffer)
        cout << row << '\n';
    cout.flush();
}

//zamienic na polimorfizm ??
// void MazeView::drawRobotMaze(const Grid<RobotCell>& state, Location currentRobotLocation) {
//     // void draw(const GameState& state) {
//     clear();
//     // drawBorder();
//
//     for (int rowNumber = 0; rowNumber < heightInCells; ++rowNumber) //y
//         for (int colNumber = 0; colNumber < widthInCells; ++colNumber) //x
//         {
//             RobotCell tempCell = state.get(colNumber, rowNumber);
//             putSprite(colNumber, rowNumber, writeRobotCell(
//                 tempCell,
//                 currentRobotLocation.x() == colNumber && currentRobotLocation.y() == rowNumber
//                 )
//             );
//         }
//
//     // drawHUD(state);
//     render();
// }


// vector<string> MazeView::writeRobotCell(const RobotCell& cell, bool isRobotThere) {
//
//     return {
//         cell.getWalls()[Direction::NORTH] == true ? "'-----'" : "'     '",
//         string(cell.getWalls()[Direction::WEST] == true ? "|" : " ")
//         + string(isRobotThere ? "R" : " ")
//         + string(isRobotThere ? "RRR" : cell.getVisited() ? " x "  : "   ")
//         + string(isRobotThere ? "R" : " ")
//         + (cell.getWalls()[Direction::EAST] == true ? "|" : " "),
//         cell.getWalls()[Direction::SOUTH] == true ? ",_____," : ",     ,"
//     };
//
//
//
// }



