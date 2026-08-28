//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include "Maze.h"
#include "Robot.h"

/**
 * @defgroup SimulationModule Simulation
 * @brief Group of classes for simulation
 */

/**
 * @ingroup SimulationModule
 * @class Simulation
 * @brief Manages the interaction between a maze and a robot, keeps logic in one place.
 *
 * Owns the robot (by pointer) and the maze (by value).
 */
class Simulation {

public:
    /**
     * @brief Constructs a simulation with a maze and a robot.
     * @param maze The maze to simulate on. Copied into the simulation.
     * @param robot Pointer to the robot. Simulation takes ownership.
     */
    Simulation(Maze& maze, Robot* robot);

    /**
     * @brief Moves through the actions needed for the simulation to make one step — delegates to robot's logic.
     * Orchestrates the relationship between Robot and Maze.
     */
    [[nodiscard]] bool nextStep() const;

    /**
     * @brief Returns a reference to the maze.
     * @return The maze used in this simulation.
     * Used for the view.
     */
    [[nodiscard]] const Maze& getMaze() const;

    /**
     * @brief Returns a pointer to the robot.
     * @return The robot used in this simulation. Cannot be modified through this pointer.
     * Used for the view.
     */
    [[nodiscard]] const Robot* getRobot() const;


    /** @brief Destructor. Deletes robot.*/
    ~Simulation();

    Simulation(const Simulation&) = delete;             ///< Copying disabled.
    Simulation& operator=(const Simulation&) = delete;   ///< Copy assignment disabled.

    /** @brief Move constructor. Transfers ownership of the robot. */
    Simulation(Simulation&& other) noexcept;

    /** @brief Move assignment. Transfers ownership of robot, deletes previous one. */
    Simulation& operator=(Simulation&& other) noexcept;

private:
    Maze maze;      ///< The maze, owned by value.
    Robot* robot;   ///< The robot, owned by pointer. Deleted in destructor.
};


#endif //CPP_SIMULATION_H
