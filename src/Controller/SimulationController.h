//
// Created by aleks on 21.06.2026.
//

#ifndef CPP_SIMULATIONCONTROLLER_H
#define CPP_SIMULATIONCONTROLLER_H

#include "../Simulation/GameState.h"
#include "../Simulation/Simulation.h"
#include "../View/MazeView.h"


enum class GameState;

class SimulationController {

public:
    Simulation create();
    void run(Simulation &simulation);
    Robot *createRobot(const string &kind, Location start, int width, int height);
    void runLoop();

private:
    GameState state = GameState::PRELIMINARY;

};



#endif //CPP_SIMULATIONCONTROLLER_H
