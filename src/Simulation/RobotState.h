//
// Created by aleks on 18.07.2026.
//

#ifndef CPP_ROBOTSTATE_H
#define CPP_ROBOTSTATE_H

#endif //CPP_ROBOTSTATE_H

/**
 * @ingroup SimulationModule
 * @enum RobotState
 * @brief Tracks what phase the robot is currently in.
 */
enum class RobotState {
    EXPLORING,   ///< Robot is discovering the maze.
    OPTIMIZING   ///< Robot finished exploring, replaying the optimal path.
};