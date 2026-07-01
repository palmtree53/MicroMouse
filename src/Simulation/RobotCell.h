//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ROBOTCELL_H
#define CPP_ROBOTCELL_H
#include "AbstractCell.h"


class RobotCell: public AbstractCell {

public:
    void setVisited() { visited = true; };
    [[nodiscard]] bool getVisited() const { return visited; };

private:
    bool visited = false;

};



#endif //CPP_ROBOTCELL_H
