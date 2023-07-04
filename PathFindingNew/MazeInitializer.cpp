#include "MazeInitializer.hpp"


/* initialise la position de The Guy dans le labyrinthe et renvoie un vector<int> représentant ses coordonnées */
vector<int> initializeThePositionGuy(deque<deque<string>>& maze)
{
    vector<int> theGuyInitialPosition = { VISION_RANGE, 2 };

    maze[VISION_RANGE][VISION_RANGE] = THE_GUY;

    return theGuyInitialPosition;
}

/* initialisation de labyrinthe visible par The Guy */
deque<deque<string>> initializeMaze()
{
    deque<deque<string>> initialMaze;
    deque<string> newColumn;
    string newCell;

    for (int x = 0; x < (2 * VISION_RANGE + 1); x++)
    {
        for (int y = 0; y < (2 * VISION_RANGE + 1); y++)
        {
            newCell = generateRandomCellContent();
            newColumn.push_back(newCell);
        }
        initialMaze.push_back(newColumn);
        newColumn.clear();
    }

    return initialMaze;
}