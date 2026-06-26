//
// Created by aleks on 22.06.2026.
//

#include "GridLoader.h"

#include "../Simulation/Maze.h"


using namespace std;


bool has(const string& s, char c) { return s.find(c) != string::npos; };

void from_json(const nlohmann::json& j, Cell& value) {
    const auto s = j.get<string>();
    value = Cell(has(s, 'N'), has(s, 'S'), has(s, 'E'), has(s, 'W'));
}

void from_json(const nlohmann::json& j, Location& value) {
    const auto v = j.get<vector<int>>();
    value = Location(v[0], v[1]);
}

Maze loadMaze(const string& path) {
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    vector<vector<Cell>> cells = j.at("walls").get<vector<vector<Cell>>>();
    Grid grid = Grid(cells);
    Location startLocation = j.at("start").get<Location>();
    Location endLocation = j.at("goal").get<Location>();

    Maze maze = Maze(grid, startLocation, endLocation);
    return maze;
}


