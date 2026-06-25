//
// Created by aleks on 22.06.2026.
//

#include "GridLoader.h"


using namespace std;


bool has(const std::string& s, char c) { return s.find(c) != string::npos; };

void from_json(const nlohmann::json& j, Cell& value) {
    auto s = j.get<std::string>();
    value = Cell(has(s, 'N'), has(s, 'S'), has(s, 'E'), has(s, 'W'));
}

Grid<Cell> loadMaze(const string& path) {
    ifstream in(path);
    if (!in) {
        throw std::runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    const auto cells = j.at("walls").get<std::vector<std::vector<Cell>>>();
    return Grid(cells);
}


