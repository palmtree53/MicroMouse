//
// Created by aleks on 22.06.2026.
//

#ifndef CPP_GRIDLOADER_H
#define CPP_GRIDLOADER_H

#include <string>
#include <fstream>
#include "../Simulation/Grid.h"
#include "../Simulation/Cell.h"
#include <nlohmann/json.hpp>

using namespace std;


bool has(const std::string& s, char c);

void from_json(const nlohmann::json& j, Cell& value);

Grid<Cell> loadMaze(const string& path);


#endif //CPP_GRIDLOADER_H
