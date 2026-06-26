//
// Created by aleks on 21.06.2026.
//

#ifndef CPP_SIMULATIONCONTROLLER_H
#define CPP_SIMULATIONCONTROLLER_H

#include "../Simulation/Simulation.h"
#include "../View/MazeView.h"
#include "../Adapter/GridLoader.h"


class SimulationController {

public:
    SimulationController(): view(MazeView()) {}

    Simulation create();
    void run(Simulation &simulation);


private:
    // Simulation sim;
    MazeView view;

};



#endif //CPP_SIMULATIONCONTROLLER_H
