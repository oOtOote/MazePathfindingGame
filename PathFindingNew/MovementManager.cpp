#include "MovementManager.hpp"


/* marque la nouvelle position de the guy est colorée en rouge dans le labyrinthe et ses nouvelles coordonnées sont mis à jour dans le vector<int>"theGuyCoordinates"
isNewLineAdded permet de savoir si une nouvelle ligne est ajouté. En effet, si une nouvelle ligne est ajoutée en haut du labyrinthe, tous les index sur l'axe des y seront décalés de 1.
Et si une nouvelle ligne est ajoutée à gauche, tous les index sur l'axe des x seront décalés de 1 */
void moveTheGuy(deque<deque<string>>& maze, vector<int>& theGuyCoordinates, direction theGuyDirection, bool isNewLineAdded) {

    switch (theGuyDirection)
    {
    case TOP:
        if (isNewLineAdded)
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1] + 1] = PATH;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        }
        else 
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = PATH;
            theGuyCoordinates[1] --;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        }
        break;

    case RIGHT:
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = PATH;
        theGuyCoordinates[0]++;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        break;

    case BELOW:
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = PATH;
        theGuyCoordinates[1]++;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        break;

    case LEFT:
        if (isNewLineAdded)
        {
            maze[theGuyCoordinates[0] + 1][theGuyCoordinates[1]] = PATH;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        }
        else 
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = PATH;
            theGuyCoordinates[0] --;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]] = THE_GUY;
        }
        break;
    }
}



/* permet de savoir si le mouvement de the guy implique le dévoilement d'une nouvelle partie du labyrinthe */
bool checkIfNewLineShouldBeAdded(deque<deque<string>> maze, vector<int> theGuyCoordinates, direction moveDirection)
{
    bool shouldLineBeAdded = false;

    switch (moveDirection)
    {
    case TOP:
        if (theGuyCoordinates[1] <= VISION_RANGE)
        {
            shouldLineBeAdded = true;
        }
        break;

    case RIGHT:
        if (theGuyCoordinates[0] >= (maze.size() - 1) - VISION_RANGE)
        {
            shouldLineBeAdded = true;
        }
        break;

    case BELOW:
        if (theGuyCoordinates[1] >= (maze[0].size() - 1) - VISION_RANGE)
        {
            shouldLineBeAdded = true;
        }
        break;

    case LEFT:
        if (theGuyCoordinates[0] <= VISION_RANGE)
        {
            shouldLineBeAdded = true;
        }
        break;
    }

    return shouldLineBeAdded;
}


/* permet d'ajouter une nouvelle ligne au labyrinthe */
void addNewLine(deque<deque<string>>& maze, direction newLinePosition)
{
    deque<string> newLine;
    int mazeLength = maze.size();
    int mazeHeight = maze[0].size();

    switch (newLinePosition)
    {
    case TOP:
        for (int x = 0; x < mazeLength; x++)
        {
            maze[x].push_front(generateRandomCellContent());
        };
        break;

    case RIGHT:
        for (int y = 0; y < mazeHeight; y++)
        {
            newLine.push_back(generateRandomCellContent());
        }
        maze.push_back(newLine);
        break;

    case BELOW:
        for (int x = 0; x < mazeLength; x++)
        {
            maze[x].push_back(generateRandomCellContent());
        };
        break;

    case LEFT:
        for (int y = 0; y < mazeHeight; y++)
        {
            newLine.push_back(generateRandomCellContent());
        }
        maze.push_front(newLine);
        break;
    }
}



/* sorte de "fonction mère" qui gère tous ce qui va se passer quand the guy va se déplacer */
void manageTheGuyMovement(deque<deque<string>>& maze, vector<int>& theGuyCoordinates, direction moveDirection)
{
    bool shouldNewLineBeAdded;

    switch (moveDirection)
    {
    case TOP:
        shouldNewLineBeAdded = checkIfNewLineShouldBeAdded(maze, theGuyCoordinates, moveDirection); // on vérifie si une ligne doit être ajoutée
        if (shouldNewLineBeAdded) 
        {
            addNewLine(maze, moveDirection); // on ajoute une ligne le cas échéant
        }
        moveTheGuy(maze, theGuyCoordinates, moveDirection, shouldNewLineBeAdded); // on déplace the guy dans le labyrinthe, on marque son ancienne position et on met à jour ses coordonnées
        break;

    case RIGHT:
        shouldNewLineBeAdded = checkIfNewLineShouldBeAdded(maze, theGuyCoordinates, moveDirection);
        if (shouldNewLineBeAdded) 
        {
            addNewLine(maze, moveDirection);
        }
        moveTheGuy(maze, theGuyCoordinates, moveDirection, shouldNewLineBeAdded);
        break;

    case BELOW:
        shouldNewLineBeAdded = checkIfNewLineShouldBeAdded(maze, theGuyCoordinates, moveDirection);
        if (shouldNewLineBeAdded) 
        {
            addNewLine(maze, moveDirection);
        }
        moveTheGuy(maze, theGuyCoordinates, moveDirection, shouldNewLineBeAdded);
        break;

    case LEFT:
        shouldNewLineBeAdded = checkIfNewLineShouldBeAdded(maze, theGuyCoordinates, moveDirection);
        if (shouldNewLineBeAdded) 
        {
            addNewLine(maze, moveDirection);
        }
        moveTheGuy(maze, theGuyCoordinates, moveDirection, shouldNewLineBeAdded);
        break;
    }
}