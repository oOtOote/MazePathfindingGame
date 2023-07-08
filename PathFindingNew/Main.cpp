#include "Main.hpp"

/* fonction 'chef d'orchestre' du projet */
int main()
{
    srand(time(0)); // initialise la graine du g�n�rateur pseudo-al�atoire

    startingGame();

    std::string keyboardEntry;
    direction theGuyDirection;

    Maze maze = initializeMaze();
    Coordinates theGuyCoordinates = initializeThePositionGuy(maze);

    displayMaze(maze);

    while (true) // chaque d�placement du personnage enclenche un tour de boucle
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





