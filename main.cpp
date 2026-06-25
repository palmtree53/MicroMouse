#include <iostream>

#include <windows.h>

#include "src/Simulation/Simulation.h"
#include "src/View/MazeView.h"
#include "src/Controller/SimulationController.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    SimulationController simController = SimulationController();

    Simulation sim = simController.create();
    simController.run(sim);

    return 0;
}