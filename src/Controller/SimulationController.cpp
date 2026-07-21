//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"

#include "../Simulation/RobotBFSOptimizer.h"
#include "../Simulation/RobotDfsExplorer.h"
#include "../Simulation/RobotRandomExplorer.h"
#include "../Adapter/GridLoader.h"
#include "../View/MenuView.h"
#include "../View/MazePreview.h"

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;


Simulation SimulationController::create() {
    cout<<"Started creating simulation procedure..."<<endl;

    //settings
    auto const path = loadPath(); //change paths to working directory if if necessary
    auto const algorithm = loadAlgorithm(path);
    auto const mazeWidth = loadWidth(path);
    auto const mazeHeight = loadHeight(path);

    //maze
    cout<<"Creating maze... size: w "<<mazeWidth<<", h "<<mazeHeight<<endl;
    auto maze = loadMaze(path, mazeWidth, mazeHeight);
    cout<<"Maze created."<<endl<<endl;

    //robot
    cout<<"Creating robot... algorithm: "<<algorithm<<endl;
    Robot* robot = createRobot(algorithm, maze.getStart(), maze.getGrid().getWidth(), maze.getGrid().getHeight());  //zamienic na parametry
    cout<<"Robot created."<<endl<<endl;

    //todo walidacje labiryntu
    cout<<"Initializing simulation..."<<endl;
    auto simulation = Simulation(maze, robot);
    cout<<"Simulation initialized."<<endl<<endl;

    cout<<"Loading maze first look..."<<endl;
    MazeView view(mazeWidth, mazeHeight);  //todo  czy to jest dobre rozwiązanie?
    view.drawMaze(simulation);

    cout<<"Creating simulation procedure finished successfully."<<endl;
    //todo dodac try-catch i opis etapu na ktorym nie zadzialalo?
    return simulation;
}

void SimulationController::run(Simulation &simulation) {
    MazeView view(simulation.getMaze().getGrid().getWidth(), simulation.getMaze().getGrid().getHeight());  //todo  czy to jest dobre rozwiązanie?
    const auto startTime = std::chrono::steady_clock::now();
    do {
        simulation.nextStep();
        this_thread::sleep_for(chrono::milliseconds(300));
        view.drawMaze(simulation);
        //time
        auto now = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
        cout<<"time: "<<elapsedTime<<endl;
    } while (!simulation.isFinished());
    cout<<"Simulation Ended"<<endl;
    // assertionts if robot is moving or non-ending loop or it is stuck and came is corrupted
}


Robot* SimulationController::createRobot(const std::string& kind, const Location start, const int width, const int height) {
    if (kind == "DFS") return new RobotDfsExplorer(start, width, height);
    if (kind == "BFS") return new RobotBFSOptimizer(start, width, height);
    if (kind == "RANDOM") return new RobotRandomExplorer(start, width, height);
    throw std::invalid_argument("Unknown robot type: " + kind);
}

void SimulationController::runLoop() {
    //start - menu
    char choice = 0;
    do {
        switch (state) {
            //todo przejrzec opcje wyboru i starowanie czy jest wszedzie adekwatne
            case GameState::PRELIMINARY: {
                cout<<"debug - state PRELIMINARY ------------------"<<endl; //todo debug
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
                cout<<"debug - state MAZE_PREVIEW ------------------"<<endl; //todo debug
                auto const path = loadPath();
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
                //todo zmienic funkcje tak zeby opcje i sterowanie zwiazane z opcjami byly w tym samym miejscu
                if (choice == 's') state = GameState::RUNNING;
                if (choice == 'm') state = GameState::PRELIMINARY;
                if (choice == 'v') state = GameState::MAZE_PREVIEW;
                break;
            }
            case GameState::RUNNING: {
                cout<<"debug - state RUNNING ------------------"<<endl; //todo debug
                Simulation sim = create();
                run(sim);
                state = GameState::FINISHED;
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
    cout<<endl<<"---CLOSING GAME---"<<endl;
    cout<<"GOODBYE!"<<endl;

}