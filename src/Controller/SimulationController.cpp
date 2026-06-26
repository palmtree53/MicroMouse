//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"




Simulation SimulationController::create() {

    //settings
    Grid<Cell> gridFromFIle = loadMaze("../resources/maze1.json"); //change paths to working directory if if necessary
    //todo walidacje labiryntu
    Simulation sim = Simulation(gridFromFIle);


    cout<<"Simulation initialized"<<endl;
    view.draw(sim.getMaze(), sim.getRobotLocation());

    return sim;
}


void SimulationController::run(Simulation &sim) {
    do {
        sim.nextStep();
        view.draw(sim.getMaze(), sim.getRobotLocation());
    } while (!sim.gameEnded());
    cout<<"Game Ended"<<endl;

    //todo assertionts if robot is moving or game not ended or non-ending loop

    view.draw(sim.getMaze(), sim.getRobotLocation());
}