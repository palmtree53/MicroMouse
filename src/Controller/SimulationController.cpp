//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"

#include "../Simulation/RobotBFSOptimizer.h"
#include "../Simulation/RobotDfsExplorer.h"
#include "../Adapter/GridLoader.h"
#include "../View/MenuView.h"

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;


Simulation SimulationController::create() {

    //settings
    auto const path = loadPath();
    auto const algorithm = loadAlgorithm(path); //change paths to working directory if if necessary
    auto const mazeWidth = loadWidth(path); //change paths to working directory if if necessary
    auto const mazeHeight = loadHeight(path); //change paths to working directory if if necessary

    //maze
    auto maze = loadMaze(path, mazeWidth, mazeHeight); //change paths to working directory if if necessary

    Robot* robot = createRobot(algorithm, maze.getStart(), maze.getGrid().getWidth(), maze.getGrid().getHeight());  //zamienic na parametry
    //todo walidacje labiryntu

    auto simulation = Simulation(maze, robot);
    view.drawMaze(simulation);
    cout<<"Simulation initialized"<<endl;
    return simulation;
}

void SimulationController::run(Simulation &simulation) {
    do {
        simulation.nextStep();
        this_thread::sleep_for(chrono::milliseconds(300));
        view.drawMaze(simulation);
    } while (!simulation.isFinished());
    cout<<"Game Ended"<<endl;
    // assertionts if robot is moving or non-ending loop or it is stuck and came is corrupted
}


Robot* SimulationController::createRobot(const std::string& kind, const Location start, const int width, const int height) {
    if (kind == "DFS") return new RobotDfsExplorer(start, width, height);
    if (kind == "BFS") return new RobotBFSOptimizer(start, width, height);
    // if (kind == "Random") return new RobotRandom(start, width, height);
    throw std::invalid_argument("Unknown robot type: " + kind);
}

void SimulationController::runLoop() {
    //start - menu
    char choice = 0;
    do {
        switch (state) {
            case GameState::PRELIMINARY: {
                cout<<"debug - state PRELIMINARY ------------------"<<endl; //todo debug
                do {
                    MenuView::draw();
                    cin>>choice;
                    choice = tolower(choice);
                } while (! (choice == 's' || choice == 'c'));
                if (choice == 's') state = GameState::RUNNING;
                break;
            }
            case GameState::RUNNING: {
                cout<<"debug - state RUNNING ------------------"<<endl; //todo debug
                Simulation sim = create();
                run(sim);
                if (choice == 's') state = GameState::FINISHED;
                break;
            }
            case GameState::FINISHED: {
                cout<<"debug - state FINISHED ------------------"<<endl; //todo debug
                do {
                    cout<<endl<<"ENTER M TO GO TO MAIN MENU OR C TO CLOSE"<<endl;
                    cin>>choice;
                    choice = tolower(choice);
                } while (! (choice == 'm' || choice == 'c'));
                if (choice == 'm') state = GameState::PRELIMINARY;
                break;
            }
        }

    } while (choice != 'c');
    cout<<endl<<"CLOSING GAME"<<endl;

}