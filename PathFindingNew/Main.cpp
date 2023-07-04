#include "MazeDisplayer.hpp"
#include "MazeInitializer.hpp"
#include "CellGenerator.hpp" 
#include "MovementManager.hpp"
#include "GameManager.hpp"
#include "ConstantValues.hpp"
#include "MyEnums.hpp"

using namespace std;


/* fonction 'chef d'orchestre' du projet */
int main()
{
    srand(time(0)); // initialise la graine du générateur pseudo-aléatoire

    startingGame();

    string keyboardEntry;
    direction theGuyDirection;
    bool gameOngoing = true;

    deque<deque<string>> maze = initializeMaze();
    vector<int> theGuyCoordinates = initializeThePositionGuy(maze);

    displayMaze(maze);

    while (gameOngoing) 
    {
        do
        {
            keyboardEntry = askKeyboardEntry();
            theGuyDirection = interpretKeyboardEntry(keyboardEntry);
        }
        while (checkForWall(maze, theGuyCoordinates, theGuyDirection));
        
        manageTheGuyMovement(maze, theGuyCoordinates, theGuyDirection);
        displayMaze(maze);
    }

    return 0;
}





