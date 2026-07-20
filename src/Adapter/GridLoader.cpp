//
// Created by aleks on 22.06.2026.
//

#include "GridLoader.h"
#include <fstream>
#include <stdexcept>

using namespace std;

bool has(const string& s, char c) { return s.find(c) != string::npos; };

void from_json(const nlohmann::json& j, MazeCell& value) {
    const auto s = j.get<string>();
    value = MazeCell(has(s, 'N'), has(s, 'S'), has(s, 'E'), has(s, 'W'));
}

void from_json(const nlohmann::json& j, Location& value) {
    const auto v = j.get<vector<int>>();
    value = Location(v[0], v[1]);
}

Maze loadMaze(const string& path, int w, int h) {
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    vector<vector<MazeCell>> cells = j.at("walls").get<vector<vector<MazeCell>>>();
    validateGrid(w, h, cells);
    Grid grid = Grid(cells);
    //walidacja na wymianr

    Location startLocation = j.at("start").get<Location>();
    Location endLocation = j.at("goal").get<Location>();

    Maze maze = Maze(grid, startLocation, endLocation);
    return maze;
}

void validateGrid(int w, int h, const vector<vector<MazeCell>>& cells) {
    bool heightError = false;
    vector<pair<int, int>> widthErrors;
    if (cells.size() != h) heightError = true;
    for (int i = 0; i<cells.size(); i++) {
        if (cells[i].size() != w) widthErrors.emplace_back(i+1, cells[i].size());
    }
    if (heightError || !widthErrors.empty()) {
        string errorMessage;
        errorMessage += heightError ? "Invalid maze height: " + to_string(cells.size()) + " when expected: " + to_string(h) + "\n": "";
        for (auto error: widthErrors) {
            errorMessage += "Invalid maze width in line: " + to_string(error.first) + ", width:  "+ to_string(error.second) + " when expected: " + to_string(w) + "\n";
        }
        throw domain_error(errorMessage);
    }
}

string loadPath() {
    string path = "../resources/settings.json";
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    auto algorithm = j.at("mazePath").get<string>();
    return algorithm;
}

string loadAlgorithm(const string& path) {
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    auto algorithm = j.at("algorithm").get<string>();
    return algorithm;
}


int loadWidth(const string& path) {
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    auto algorithm = j.at("mazeWidth").get<int>();
    return algorithm;
}

int loadHeight(const string& path) {
    ifstream in(path);
    if (!in) {
        throw runtime_error("Could not open file: " + path);
    }
    nlohmann::json j;
    in >> j;

    auto algorithm = j.at("mazeHeight").get<int>();
    return algorithm;
}

