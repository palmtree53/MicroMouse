//
// Created by aleks on 20.06.2026.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H

#include "Maze.h"
#include "RobotCell.h"
#include "RobotState.h"

using namespace std;


class Robot {

public:
    virtual ~Robot() = default;

    [[nodiscard]] Location getLocation() const;
    void addMove(Location location);
    void updateMap(Location location, const map<Direction, bool>& walls);

    void updateExplorationPathMap(Location location);

    void updateOptimizationPathMap(Location location);

    [[nodiscard]] bool visitedLocation(Location location) const;

    virtual const Grid<RobotCell>& getGridMap() const = 0;
    vector<Location> getMoves() {return moves;};

    virtual void nextStep(const Maze& maze) = 0;
    [[nodiscard]] bool isFinished() const;
    [[nodiscard]] int getStepNumber() const { return stepNumber; }
    [[nodiscard]] int getOptimalPathStepNumber() const { return optimaPathStepNumber; } //todo jak to rozwiązać?

protected:
    explicit Robot(Location location, int mazeWeight, int mazeHeight);

    Location currentLocation;
    vector<Location> moves;
    Grid<RobotCell> gridMap; //usunąć to kiedy zamienię przeliczanie inicjalne na krok-po-kroku
    Grid<RobotCell> explorationMap;
    Grid<RobotCell> optimalPathMap; //todo jak to rozwiązać?
    bool finished = false;

    int stepNumber = 0;
    int optimaPathStepNumber = 0;

    RobotState state = RobotState::EXPLORING;



};



#endif //CPP_ROBOT_H
