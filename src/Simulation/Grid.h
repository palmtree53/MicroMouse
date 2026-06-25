//
// Created by aleks on 14.04.2026.
//

#include <vector>

#ifndef CPP_GRID_H
#define CPP_GRID_H

using namespace std;


template<typename T> class Grid {

public:
    explicit Grid(vector<vector<T>> v) : width(getWidth(v)), height(getHeight(v)), cells(v) {}
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    T get(int x, int y) const {
        return cells[y][x];
    }
    void set(int x, int y, T v) {
        //boundaries check
        cells[y][x] = v;
    }

private:
    int width, //x
    height; //y
    vector<vector<T>> cells;

    int getWidth(const std::vector<std::vector<T>>& v) {
        return v.empty() ? 0 : static_cast<int>(v[0].size());
    }
    int getHeight(const std::vector<std::vector<T>>& v) {
        return static_cast<int>(v.size());
    }

};



#endif //CPP_GRID_H
