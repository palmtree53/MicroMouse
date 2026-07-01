//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"

#include "../Simulation/algorithms/ExplorationAlgRandom.h"


Simulation SimulationController::create() {

    //settings
    auto maze = loadMaze("../resources/maze1.json"); //change paths to working directory if if necessary
    // auto algorithm = ExplorationAlgRandom{};

    auto robot = Robot(maze.getStart(), maze.getGrid().getWidth(), maze.getGrid().getHeight());
    //todo walidacje labiryntu

    auto simulation = Simulation(maze, robot);


    cout<<"Simulation initialized"<<endl;
    view.drawMaze(simulation.getMaze(), simulation.getRobotLocation());

    return simulation;
}
//how is it reusable?


// void SimulationController::run(Simulation &simulation) {
//     do {
//         simulation.nextStep();
//         view.draw(simulation.getMaze(), simulation.getRobotLocation());
//     } while (!simulation.gameEnded());
//     cout<<"Game Ended"<<endl;
//
//     //todo assertionts if robot is moving or game not ended or non-ending loop
//
//     view.draw(simulation.getMaze(), simulation.getRobotLocation());
// }

void SimulationController::run(Simulation &simulation) {

    auto algorithm = ExplorationAlgRandom{};
    algorithm.exploreMaze(simulation.getMaze().getStart(),  simulation.getMaze(),  simulation.getRobot());


    //debug only
    auto moves = simulation.getRobot().getMoves();
    cout<<"list of moves"<<endl;
    for (auto move: moves) {
        cout<<move.x()<<","<<move.y()<<endl;
    }

    // do {
    //     simulation.nextStep();
    //     view.drawMaze(simulation.getMaze(), simulation.getRobotLocation());
    // } while (!simulation.gameEnded());
    // cout<<"Game Ended"<<endl;
    //
    // //todo assertionts if robot is moving or game not ended or non-ending loop
    //
    // view.drawMaze(simulation.getMaze(), simulation.getRobotLocation());
}