//
// Created by aleks on 28.06.2026.
//

#ifndef CPP_ROBOTCELL_H
#define CPP_ROBOTCELL_H
#include "AbstractCell.h"


/**
 * @ingroup SimulationModule
 * @class RobotCell
 * @brief A cell used by the robot to track which parts of the maze it has been to.
 * Inherits wall data from AbstractCell, adds a visited flag.
 */
class RobotCell: public AbstractCell {

public:
    /** @brief Marks this cell as visited by the robot. */
    void setVisited() { visited = true; };

    /** @brief Checks if the robot has been to this cell. */
    [[nodiscard]] bool getVisited() const { return visited; };

private:
    bool visited = false;
};



#endif //CPP_ROBOTCELL_H
