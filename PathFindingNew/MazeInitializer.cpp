#include "MazeInitializer.hpp"


/* initialise la position de The Guy dans le labyrinthe et renvoie un vector<int> représentant ses coordonnées */
Coordinates initializeThePositionGuy(Maze& maze)
{
    Coordinates theGuyInitialPosition = { VISION_RANGE, VISION_RANGE };

    maze[VISION_RANGE][VISION_RANGE]->isTheGuyHere = true;

    return theGuyInitialPosition;
}


/* initialisation du labyrinthe visible par The Guy */
Maze initializeMaze()
{
    Maze initialMaze;
    
    for (int x = 0; x < (2 * VISION_RANGE + 1); x++)
    {
        std::deque<std::unique_ptr<Cell>> newColumn;

        for (int y = 0; y < (2 * VISION_RANGE + 1); y++)
        {
            newColumn.push_back(std::make_unique<Cell>(generateRandomCellContent(), false, false));
        }
        initialMaze.push_back(std::move(newColumn));
    }

    return initialMaze;
}