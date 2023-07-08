#include "Main.hpp"

/* fonction 'chef d'orchestre' du projet */
int main()
{
    srand(time(0)); // initialise la graine du générateur pseudo-aléatoire

    startingGame();

    std::string keyboardEntry;
    direction theGuyDirection;

    Maze maze = initializeMaze();
    Coordinates theGuyCoordinates = initializeThePositionGuy(maze);

    displayMaze(maze);

    while (true) // chaque déplacement du personnage enclenche un tour de boucle
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





