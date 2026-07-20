//
// Created by aleks on 22.06.2026.
//

#ifndef CPP_GRIDLOADER_H
#define CPP_GRIDLOADER_H

#include <string>
#include <nlohmann/json.hpp>

#include "../Simulation/Maze.h"

using namespace std;

bool has(const std::string& s, char c);
void from_json(const nlohmann::json& j, MazeCell& value);
Maze loadMaze(const string& path, int w, int h);
string loadPath();
string loadAlgorithm(const string& path);
int loadWidth(const string& path);
int loadHeight(const string& path);
void validateGrid(int w, int h, const vector<vector<MazeCell>>& cells);


#endif //CPP_GRIDLOADER_H
