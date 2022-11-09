// maze-solver.cpp
//
// This program fills in a maze with random positions and then runs the solver to solve it.
// The moves are saved in two arrays, which store the X/Y coordinates we are moving to.
// They are output in main in forward order.
//
#include "Maze.h"
using namespace std;

int main()
{
    Maze maze_1;

    // Example of how to print the maze at current point

    /*Maze::printMaze(maze_1.maze, maze_1.getXLocation(), maze_1.getYLocation());*/

    maze_1.solveMaze();
}
