//
// Created by aleks on 22.06.2026.
//

#ifndef CPP_GRIDLOADER_H
#define CPP_GRIDLOADER_H

#include <array>
#include <map>
#include <string>
#include <fstream>
#include "../Simulation/Direction.h"
#include "../Simulation/Grid.h"
#include "../Simulation/Cell.h"
#include <nlohmann/json.hpp>

using namespace std;

class GridLoader {
public:
    static Cell parseCell(const string& s);
    template<int W, int H> static Grid<Cell, W, H> loadMaze(const string& path) {
        ifstream in(path);
        nlohmann::json j;
        in >> j;

        Grid<Cell, W, H> grid;
        const auto& rows = j["walls"];                 // rows[y][x]
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x)
                grid.set(x, y, parseCell(rows[y][x].get<string>()));
        return grid;
    }

private:
    static bool has(const std::string& s, char c);
};



#endif //CPP_GRIDLOADER_H
