//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"

#include "../Simulation/RobotDfsExplorer.h"
#include "../Simulation/RobotRandomExplorer.h"
#include "../Adapter/GridLoader.h"
#include "../View/MenuView.h"
#include "../View/MazePreview.h"

#include <thread>
#include <chrono>
#include <iostream>

#include "../Simulation/RobotBFSOptimizerNew.h"

using namespace std;


Simulation SimulationController::createSimulation() {
    system("cls");
    cout<<"Started creating simulation procedure..."<<endl;

    //settings
    std::string mazePath;
    std::string algorithm;
    int startScreenWaitTime;
    loadSettings(mazePath, algorithm, simulationRefreshTimeInMils, startScreenWaitTime, isDebug);

    auto const mazeWidth = loadWidth(mazePath); // TODO!!! change paths to working directory if if necessary
    auto const mazeHeight = loadHeight(mazePath);

    //maze
    cout<<"Creating maze... size: w "<<mazeWidth<<", h "<<mazeHeight<<endl;
    auto maze = loadMaze(mazePath, mazeWidth, mazeHeight);
    cout<<"Maze created."<<endl<<endl;
    cout<<"Start location: ("<<maze.getStart().x()<<", "<<maze.getStart().y()<<")"<<endl;
    cout<<"Start location: ("<<maze.getEnd().x()<<", "<<maze.getEnd().y()<<")"<<endl;

    //robot
    cout<<"Creating robot... algorithm: "<<algorithm<<endl;
    Robot* robot = createRobot(algorithm, maze.getStart(), maze.getGrid().getWidth(), maze.getGrid().getHeight());
    cout<<"Robot created."<<endl<<endl;

    cout<<"Initializing simulation..."<<endl;
    auto simulation = Simulation(maze, robot);
    cout<<"Simulation initialized."<<endl<<endl;

    cout<<"Creating simulation procedure finished successfully."<<endl;
    this_thread::sleep_for(chrono::milliseconds(startScreenWaitTime));
    system("cls");

    return simulation;
}

void SimulationController::run(Simulation &simulation) {
    MazeView view(simulation.getMaze().getGrid().getWidth(), simulation.getMaze().getGrid().getHeight());
    const auto startTime = std::chrono::steady_clock::now();
    bool finished = false;
    do {
        finished = simulation.nextStep();
        view.drawMaze(simulation);
        this_thread::sleep_for(chrono::milliseconds(simulationRefreshTimeInMils));
        //time
        auto now = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
        cout<<"time: "<<elapsedTime<<endl;
    } while (!finished);
    cout<<"Simulation Ended"<<endl;
    // assertionts if robot is moving or non-ending loop or it is stuck or maze is corrupted
}


Robot* SimulationController::createRobot(const std::string& kind, const Location start, const int width, const int height) {
    if (kind == "DFS") return new RobotDfsExplorer(start, width, height);
    if (kind == "BFS") return new RobotBFSOptimizerNew(start, width, height);
    if (kind == "RANDOM") return new RobotRandomExplorer(start, width, height);
    throw std::invalid_argument("Unknown robot type: " + kind);
}

void SimulationController::runApplication() {
    //start - menu
    char choice = 0;
    do {
        switch (state) {
            case GameState::PRELIMINARY: {
                debug("state PRELIMINARY");
                MenuView::draw();
                do {
                    cin>>choice;
                    choice = tolower(choice);
                } while (! (choice == 's' || choice == 'c'|| choice == 'v'));
                if (choice == 's') state = GameState::RUNNING;
                if (choice == 'v') state = GameState::MAZE_PREVIEW;
                break;
            }
            case GameState::MAZE_PREVIEW: {
                debug("state MAZE_PREVIEW");
                string path;
                loadMazePath(path);
                auto const mazeWidth = loadWidth(path);
                auto const mazeHeight = loadHeight(path);
                cout << "Creating maze... size: w " << mazeWidth << ", h " << mazeHeight << endl;
                auto maze = loadMaze(path, mazeWidth, mazeHeight);
                cout << "Maze created." << endl << endl;
                MazePreview::draw(maze);

                do {
                    cin>>choice;
                    choice = tolower(choice);
                } while (! (choice == 's' || choice == 'm'|| choice == 'v'));
                if (choice == 's') state = GameState::RUNNING;
                if (choice == 'm') state = GameState::PRELIMINARY;
                if (choice == 'v') state = GameState::MAZE_PREVIEW;
                break;
            }
            case GameState::RUNNING: {
                debug("state RUNNING");
                Simulation sim = createSimulation();
                run(sim);
                state = GameState::FINISHED;
                break;
            }
            case GameState::FINISHED: {
                debug("state FINISHED");
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
    cout<<endl<<"---CLOSING GAME---"<<endl;
    cout<<"GOODBYE!"<<endl;
}

void SimulationController::debug(string message) const {
    if (isDebug) cout<<"-----debug-----"<<message<<endl;
}