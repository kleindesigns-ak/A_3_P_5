#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
/*
class Maze {
private:
    const static int WIDTH = 20;
    const static int HEIGHT = 20;

    // Arrays used in tandem to keep track of moves
    char maze[WIDTH][HEIGHT];
    bool visited[WIDTH][HEIGHT];

    // Position Tracking
    int x, y;

    // Recursive Solution Tracking
    int solutionX[(HEIGHT-2)*(WIDTH-2)], solutionY[(HEIGHT-2)*(WIDTH-2)];
    int numPoints = 0;

    void initializeMazeWithSpaces();
    void encapsulateBorder();
    void fillQuarterOfMaze();
    void createStartingPoint();
    void createEndPoint();
    void initializeVisitedArr();
    void printMaze(int curx, int cury);
    bool search(int x, int y,
                int solutionX[], int solutionY[], int &numEntries);
    bool validMove(int newX, int newY);
    static void addToArrays(int x[], int y[], int &numEntries, int xVal, int yVal);
    bool move(int &curX, int &curY, int newX, int newY);
public:
    Maze();
    void createMaze();
    void solveMaze();
};*/

class Maze {
private:
    const static int WIDTH = 20;
    const static int HEIGHT = 20;

    int x;
    int y;

    int exitX;
    int exitY;

    // HELPERS
    void initializeRandomMaze();
    void initializeBoolArr();
public:
    char maze[HEIGHT][WIDTH];
    bool visited[HEIGHT][WIDTH];

    Maze();
    int getXLocation();
    int getYLocation();

    void solveMaze();
};