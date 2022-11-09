#include "Maze.h"

/*
Maze::Maze() {
    createMaze();
    initializeVisitedArr();
}

void Maze::createMaze() {
    initializeMazeWithSpaces();
    encapsulateBorder();
    fillQuarterOfMaze();
    createStartingPoint();
    createEndPoint();
}

void Maze::initializeVisitedArr() {
    // Initialize visited locations to false
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            visited[y][x] = false;
    visited[y][x] = true;
}

void Maze::initializeMazeWithSpaces() {
    // All blank
    for (int eaX = 0; eaX < WIDTH; eaX++)
        for (int eaY = 0; eaY < HEIGHT; eaY++)
            maze[eaY][eaX] = ' ';
}

void Maze::encapsulateBorder() {
    // Borders with X
    for (int eaX = 0; eaX < WIDTH; eaX++)
    {
        maze[0][eaX] = 'X';
        maze[HEIGHT-1][eaX] = 'X';
    }
    for (int eaY = 0; eaY < HEIGHT; eaY++)
    {
        maze[eaY][0] = 'X';
        maze[eaY][WIDTH-1] = 'X';
    }
}

void Maze::fillQuarterOfMaze() {
    // ***** Randomly fill in 25% of the middle
    int numCells = static_cast<int>((HEIGHT-2)*(WIDTH-2)*0.25);
    int count = 0;
    while (count < numCells)
    {
        int tempX = (rand() % (WIDTH-2)) +1;
        int tempY = (rand() % (HEIGHT-2)) +1;
        if (maze[tempY][tempX]==' ')
        {
            maze[tempY][tempX]='X';
            count++;
        }
    }
}

void Maze::createStartingPoint() {
    // ***** Pick a random start and end that is not a wall *****
    int tempX = (rand() % (WIDTH-2)) +1;
    int tempY = (rand() % (HEIGHT-2)) +1;
    while (maze[tempY][tempX]=='X')
    {
        tempX = (rand() % (WIDTH-2)) +1;
        tempY = (rand() % (HEIGHT-2)) +1;
    }
}

void Maze::createEndPoint() {
    // ***** Pick a random end position that is not a wall *******
    int exitX = (rand() % (WIDTH-2)) +1;
    int exitY = (rand() % (HEIGHT-2)) +1;
    while (maze[exitY][exitX]=='X')
    {
        exitX = (rand() % (WIDTH-2)) +1;
        exitY = (rand() % (HEIGHT-2)) +1;
    }
    maze[exitY][exitX]='E';
}

void Maze::solveMaze() {
    bool found = search(x,y,solutionX,solutionY,numPoints);
    if (!found)
        cout << "No solution found.";
    else
    {
        cout << "Solution found!  Here is the path from the start." << endl;
        for (int i = numPoints-1; i >= 0; i--)
        {
            printMaze(solutionX[i], solutionY[i]);
            cout << endl;
        }
    }
}

void Maze::printMaze(int curx, int cury) {
    // Display the maze in ASCII
    for (int y=0; y < HEIGHT;y++)
    {
        for (int x=0; x < WIDTH; x++)
        {
            if ((x==curx) && (y==cury))
                cout << "@";
            else
                cout << maze[y][x];
        }
        cout << endl;
    }
}

bool Maze::search(int x, int y,
            int solutionX[], int solutionY[], int &numEntries) {
// Recursively search from x,y until we find the exit
    bool foundExit = false;

    if (maze[y][x]=='E')
        return true;
    visited[y][x]=true;
    if (validMove(x,y-1))
        foundExit = search(x,y-1,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x,y+1)))
        foundExit = search(x,y+1,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x-1,y)))
        foundExit = search(x-1,y,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x+1,y)))
        foundExit = search(x+1,y,solutionX,solutionY,numEntries);

    if (foundExit)
    {
        // Remember coordinates we found the exit in the solution arrays
        addToArrays(solutionX, solutionY, numEntries, x, y);
        return true;
    }
    return false;
}

// Return true or false if moving to the specified coordinate is valid
// Return false if we have been to this cell already
bool Maze::validMove(int newX, int newY)
{
    // Check for going off the maze edges
    if (newX < 0 || newX >= WIDTH)
        return false;
    if (newY < 0 || newY >= HEIGHT)
        return false;
    // Check if target is a wall
    if (maze[newY][newX]=='X')
        return false;
    // Check if visited
    if (visited[newY][newX])
        return false;
    return true;
}

// This new function adds two numbers to the arrays and increments the count of how many
// numbers have been added. It assumes the arrays have been created big enough to not
// have overflow. It is used to remember the coordinates of our solution.
void Maze::addToArrays(int x[], int y[], int &numEntries, int xVal, int yVal)
{
    x[numEntries] = xVal;
    y[numEntries] = yVal;
    numEntries++;
}

// Make the move on the maze to move to a new coordinate
// I passed curX and curY by reference so they are changed to
// the new coordinates.  Here we assume the move coordinates are valid.
// This returns true if we move onto the exit, false otherwise.
// Also update the visited array.
bool Maze::move(int &curX, int &curY, int newX, int newY)
{
    bool foundExit = false;
    if (maze[newY][newX]=='E') 	// Check for exit
        foundExit = true;
    curX = newX;			// Update location
    curY = newY;
    visited[curY][curX] = true;

    return foundExit;
}*/

Maze::Maze() {
    srand(time(nullptr));
    initializeRandomMaze();
    initializeBoolArr();
}

void Maze::initializeRandomMaze() {
    // All blank
    for (int xUnit = 0; xUnit < WIDTH; xUnit++)
        for (int yUnit = 0; yUnit < HEIGHT; yUnit++)
            maze[yUnit][xUnit] = ' ';
    // Borders with X
    for (int xUnit = 0; xUnit < WIDTH; xUnit++) {
        maze[0][xUnit] = 'X';
        maze[HEIGHT-1][xUnit] = 'X';
    }
    for (int yUnit = 0; yUnit < HEIGHT; yUnit++) {
        maze[yUnit][0] = 'X';
        maze[yUnit][WIDTH - 1] = 'X';
    }

    // ***** Randomly fill in 25% of the middle
    int numCells = static_cast<int>((HEIGHT-2)*(WIDTH-2)*0.25);
    int count = 0;
    while (count < numCells) {
        int xUnit = (rand() % (WIDTH - 2)) + 1;
        int yUnit = (rand() % (HEIGHT - 2)) + 1;
        if (maze[yUnit][xUnit] == ' ')
        {
            maze[yUnit][xUnit]='X';
            count++;
        }
    }

    // ***** Pick a random start and end that is not a wall *****
    this->x = (rand() % (WIDTH - 2)) + 1;
    this->y = (rand() % (HEIGHT - 2)) + 1;
    while (maze[this->y][this->x] == 'X')
    {
        this->x = (rand() % (WIDTH - 2)) + 1;
        this->y = (rand() % (HEIGHT - 2)) + 1;
    }

    // At this point, (x,y) contains our start position
    // ***** Pick a random end position that is not a wall *******
    this->exitX = (rand() % (WIDTH-2)) +1;
    this->exitY = (rand() % (HEIGHT-2)) +1;
    while (maze[this->exitY][this->exitX]=='X')
    {
        this->exitX = (rand() % (WIDTH-2)) +1;
        this->exitY = (rand() % (HEIGHT-2)) +1;
    }
    maze[this->exitY][this->exitX]='E';
}

void Maze::initializeBoolArr() {
    // Initialize visited locations to false
    for (int xUnit = 0; xUnit < WIDTH; xUnit++)
        for (int yUnit = 0; yUnit < HEIGHT; yUnit++)
            this->visited[yUnit][xUnit] = false;
    this->visited[y][x] = true;
}

int Maze::getXLocation() {
    return x;
}

int Maze::getYLocation() {
    return y;
}


void Maze::solveMaze() {
    // Here I created arrays to store the x/y coordinates for the path of our solution.
    // The array is of size [HEIGHT-2]*[WIDTH-2] since we'll never exceed that size.
    // I also made a variable to count how many entries we make.
    // It would probably be more convenient to make a class to store this data rather than
    // have two separate arrays!

    int solutionX[(HEIGHT-2)*(WIDTH-2)], solutionY[(HEIGHT-2)*(WIDTH-2)];
    int numPoints = 0;

    bool found = search(x, y, solutionX, solutionY, numPoints);
    if (!found)
        cout << "No solution found.";
    else
    {
        cout << "Solution found!  Here is the path from the start." << endl;
        for (int i = numPoints-1; i >= 0; i--)
        {
            printMaze(maze, solutionX[i], solutionY[i]);
            cout << endl;
        }
    }
}

// Display the maze in ASCII
void Maze::printMaze(char (*maze)[20], int curX, int curY) {
    for (int yUnits=0; yUnits < HEIGHT; yUnits++)
    {
        for (int xUnits=0; xUnits < WIDTH; xUnits++)
        {
            if ((xUnits == curX) && (yUnits == curY))
                cout << "@";
            else
                cout << maze[yUnits][xUnits];
        }
        cout << endl;
    }
}

bool

// Recursively search from x,y until we find the exit
Maze::search(int x, int y, int *solutionX, int *solutionY, int &numEntries) {
    bool foundExit = false;

    if (maze[y][x]=='E')
        return true;
    visited[y][x]=true;
    if (validMove(x,y-1))
        foundExit = search(x,y-1,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x,y+1)))
        foundExit = search(x,y+1,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x-1,y)))
        foundExit = search(x-1,y,solutionX,solutionY,numEntries);
    if (!foundExit && (validMove(x+1,y)))
        foundExit = search(x+1,y,solutionX,solutionY,numEntries);

    if (foundExit)
    {
        // Remember coordinates we found the exit in the solution arrays
        addToArrays(solutionX, solutionY, numEntries, x, y);
        return true;
    }
    return false;
}

// Return true or false if moving to the specified coordinate is valid
// Return false if we have been to this cell already
bool Maze::validMove(int newX, int newY) {
    // Check for going off the maze edges
    if (newX < 0 || newX >= WIDTH)
        return false;
    if (newY < 0 || newY >= HEIGHT)
        return false;
    // Check if target is a wall
    if (maze[newY][newX]=='X')
        return false;
    // Check if visited
    if (visited[newY][newX])
        return false;
    return true;
}

// This new function adds two numbers to the arrays and increments the count of how many
// numbers have been added. It assumes the arrays have been created big enough to not
// have overflow. It is used to remember the coordinates of our solution.
void Maze::addToArrays(int *x, int *y, int &numEntries, int xVal, int yVal) {
    x[numEntries] = xVal;
    y[numEntries] = yVal;
    numEntries++;
}



