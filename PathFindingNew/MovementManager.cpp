#include "MovementManager.hpp"


/* marque la nouvelle position de the guy est colorée en rouge dans le labyrinthe et ses nouvelles coordonnées sont mis à jour dans le vector<int>"theGuyCoordinates"
isNewLineAdded permet de savoir si une nouvelle ligne est ajouté. En effet, si une nouvelle ligne est ajoutée en haut du labyrinthe, tous les index sur l'axe des y seront décalés de 1.
Et si une nouvelle ligne est ajoutée à gauche, tous les index sur l'axe des x seront décalés de 1 */
void moveTheGuy(Maze& maze, Coordinates& theGuyCoordinates, direction theGuyDirection, bool isNewLineAdded)
{
    switch (theGuyDirection)
    {
    case TOP:
        if (isNewLineAdded)
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1] + 1]->isTheGuyHere = false;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1] + 1]->isRunThrough = true;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        }
        else 
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = false;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isRunThrough = true;
            theGuyCoordinates[1] --;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        }
        break;

    case RIGHT:
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = false;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isRunThrough = true;
        theGuyCoordinates[0]++;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        break;

    case BELOW:
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = false;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isRunThrough = true;
        theGuyCoordinates[1]++;
        maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        break;

    case LEFT:
        if (isNewLineAdded)
        {
            maze[theGuyCoordinates[0] + 1][theGuyCoordinates[1]]->isTheGuyHere = false;
            maze[theGuyCoordinates[0] + 1][theGuyCoordinates[1]]->isRunThrough = true;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        }
        else 
        {
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = false;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isRunThrough = true;
            theGuyCoordinates[0] --;
            maze[theGuyCoordinates[0]][theGuyCoordinates[1]]->isTheGuyHere = true;
        }
        break;
    }
}



/* permet de savoir si le mouvement de the guy implique le dévoilement d'une nouvelle partie du labyrinthe */
bool checkIfNewLineShouldBeAdded(const Maze& maze, const Coordinates& theGuyCoordinates, direction moveDirection)
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
void addNewLine(Maze& maze, direction newLinePosition)
{
    std::deque<std::unique_ptr<Cell>> newLine;
    int mazeLength = maze.size();
    int mazeHeight = maze[0].size();

    switch (newLinePosition)
    {
    case TOP:
        for (int x = 0; x < mazeLength; x++)
        {
            maze[x].push_front(std::make_unique<Cell>(generateRandomCellContent(),false, false));
        };
        break;

    case RIGHT:
        for (int y = 0; y < mazeHeight; y++)
        {
            newLine.push_back(std::make_unique<Cell>(generateRandomCellContent(), false, false));
        }
        maze.push_back(std::move(newLine));
        break;

    case BELOW:
        for (int x = 0; x < mazeLength; x++)
        {
            maze[x].push_back(std::make_unique<Cell>(generateRandomCellContent(), false, false));
        };
        break;

    case LEFT:
        for (int y = 0; y < mazeHeight; y++)
        {
            newLine.push_back(std::make_unique<Cell>(generateRandomCellContent(), false, false));
        }
        maze.push_front(std::move(newLine));
        break;
    }
}


/* sorte de "fonction mère" qui gère tous ce qui va se passer quand the guy va se déplacer */
void manageTheGuyMovement(Maze& maze, Coordinates& theGuyCoordinates, direction moveDirection)
{
    bool shouldNewLineBeAdded = checkIfNewLineShouldBeAdded(maze, theGuyCoordinates, moveDirection);

    if (shouldNewLineBeAdded)
    {
        addNewLine(maze, moveDirection);
    }

    moveTheGuy(maze, theGuyCoordinates, moveDirection, shouldNewLineBeAdded);
}