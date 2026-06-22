//
// Created by aleks on 14.06.2026.
//

#include "MazeView.h"


//todo robot location and destination location - in cell or separate
void MazeView::draw(const Maze& state, Location robotLocation) {
    // void draw(const GameState& state) {
    clear();
    // drawBorder();

    for (int rowNumber = 0; rowNumber < defaultHeight; ++rowNumber) //y
        for (int colNumber = 0; colNumber < defaultWidth; ++colNumber) //x
        {
            Cell tempCell = state.getGrid().get(colNumber, rowNumber);
            putSprite(colNumber, rowNumber, writeCell(
                tempCell,
                robotLocation.x() == colNumber && robotLocation.y() == rowNumber,
                state.getEnd().x() == colNumber && state.getEnd().y() == rowNumber
                )
            );
        }

    // drawHUD(state);
    render();
}

void MazeView::clear() {
    for (auto& row : buffer)
        row.assign(w, 'e');
}

void MazeView::put(int x, int y, char c) {
    if (x >= 0 && x < w && y >= 0 && y < h)
        buffer[y][x] = c;
}

void MazeView::putSprite(int x, int y, const vector<string>& sprite) {
    for (int row = 0; row < static_cast<int>(sprite.size()); ++row)//x, y są w ramach rozmiaru 16*16
        for (int col = 0; col < static_cast<int>(sprite[row].size()); ++col)
            // if (sprite[row][col] != ' ')   // treat space as transparent
                put(defaultWidthSize*x + col, defaultHeightSize*y + row, sprite[row][col]);
}

vector<string> MazeView::writeCell(Cell cell, const bool &containsRobot, const bool &containsTarget) {

    return {
        cell.getWalls()[Direction::NORTH] == true ? "'-----'" : "'     '",
        string(cell.getWalls()[Direction::WEST] == true ? "|" : " ")
        + " "
        + string(containsRobot && containsTarget ? "R F"  : containsTarget ? "  F" : containsRobot ? "R  " : "   ")
        + " "
        + (cell.getWalls()[Direction::EAST] == true ? "|" : " "),
        cell.getWalls()[Direction::SOUTH] == true ? ",_____," : ",     ,"
    };



}

void MazeView::render() const {
    // std::cout << "\033[H";
    for (const auto& row : buffer)
        std::cout << row << '\n';
    std::cout.flush();
}



