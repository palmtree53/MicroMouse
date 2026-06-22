//
// Created by aleks on 14.04.2026.
//

#include <array>

#ifndef CPP_GRID_H
#define CPP_GRID_H

using namespace std;


template<typename T, int W, int H> class Grid {

public:
    T get(int x, int y) const {
        return cells[y][x];
    }
    Grid() = default; //Grid() {}
    int width() { return W; }
    int height() { return H; }
    void set(int x, int y, T v) { cells[y][x] = v; }

private:
    array<array<T, H>, W> cells = {};

};



#endif //CPP_GRID_H
