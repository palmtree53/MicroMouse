//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ABSTRACTCELL_H
#define CPP_ABSTRACTCELL_H

#include <map>
#include <bits/basic_string.h>

#include "Direction.h"

using namespace std;

class AbstractCell {
public:
    [[nodiscard]] map<Direction, bool> getWalls() const { return walls; }
    virtual ~AbstractCell() = default;

    //setwalls nie powinno być w maze? w teorii??
    void setWalls(bool north, bool south, bool east, bool west);
    void setWalls(map<Direction, bool> walls);


protected:
    AbstractCell(): walls({}) {}
    AbstractCell(bool north, bool south, bool east, bool west);

    map<Direction, bool> walls;

};

#endif //CPP_ABSTRACTCELL_H
