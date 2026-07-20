//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ABSTRACTCELL_H
#define CPP_ABSTRACTCELL_H

#include <map>

#include "Direction.h"


class AbstractCell {
public:
    virtual ~AbstractCell() = default;
    [[nodiscard]] std::map<Direction, bool> getWalls() const { return walls; }
    void setWalls(bool north, bool south, bool east, bool west);
    void setWalls(std::map<Direction, bool> walls);

protected:
    AbstractCell(): walls({}) {}
    AbstractCell(bool north, bool south, bool east, bool west);
    std::map<Direction, bool> walls;
};

#endif //CPP_ABSTRACTCELL_H
