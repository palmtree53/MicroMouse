#include <iostream>

#include <windows.h>

#include "src/Simulation/Simulation.h"
#include "src/View/MazeView.h"
#include "src/Controller/SimulationController.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.



    // TestClass::test();
    // Maze maze = Maze();
    //
    // maze.display();

    // auto grid = Grid<Cell, 16, 16>();
    // MazeView view;
    // view.draw(grid, Location(0, 0), Location(8, 8));
    //
    //
    // Simulation sim = Simulation();
    // // sim.run();

    SimulationController simController = SimulationController();

    Simulation sim = simController.create();
    simController.run(sim);

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}