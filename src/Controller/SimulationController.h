//
// Created by aleks on 21.06.2026.
//

#ifndef CPP_SIMULATIONCONTROLLER_H
#define CPP_SIMULATIONCONTROLLER_H

#include "../Simulation/GameState.h"
#include "../Simulation/Simulation.h"
#include "../View/MazeView.h"


/**
 * @ingroup SimulationModule
 * @class SimulationController
 * @brief Controls the application flow — runs the game loop and manages game states.
 * Manages views and transitions between them along the game states. When user decides to run simulation - creates and runs it.
 */
class SimulationController {

public:
    /**
     * @brief Creates a new simulation by loading settings, maze, and robot from configuration files.
     * @return Fully initialized Simulation ready to run.
     */
    Simulation createSimulation();

    /**
     * @brief Runs the simulation step by step, drawing the maze after each step until robot gives flag as finished.
     * @param simulation The simulation to run.
     */
    void run(Simulation &simulation);

    /**
     * @brief Factory method — creates a robot of the given type.
     * @param kind Robot algorithm type: "DFS", "BFS", or "RANDOM".
     * @param start Starting location on the maze.
     * @param width robot's Maze grid width.
     * @param height robot's Maze grid height.
     * @return Pointer to the created Robot. Caller takes ownership.
     * @throws std::invalid_argument If kind is not recognized.
     */
    Robot *createRobot(const string &kind, Location start, int width, int height);

    /**
     * @brief Main application loop — handles game state transitions and user input.
     *
     * Cycles through states: PRELIMINARY (menu), MAZE_PREVIEW, RUNNING, FINISHED.
     * Exits when user chooses to close.
     */
    void runApplication();

    void debug(string message) const;

private:
    GameState state = GameState::PRELIMINARY; ///< Current game state. Game always strats from PRELIMINARY (menu view).

    int simulationRefreshTimeInMils = 200;
    bool isDebug = false;
};



#endif //CPP_SIMULATIONCONTROLLER_H
