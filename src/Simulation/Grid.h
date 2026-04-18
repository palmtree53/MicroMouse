//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_GRID_H
#define CPP_GRID_H
#include "Location.h"


template<typename T, int W, int H> class Grid {

    public:
    T get(Location location) {
        return cells[location.x()][location.y()];
    }
    void update(Location location, T cell) {
        cells[location.x()][location.y()] = cell;
    }
    Grid(T table[W][H]) {
        cells = table;
    }

    private:
    T cells[W][H] = {};

};



#endif //CPP_GRID_H
