#include "mazeDisplayer.hpp"


/* permet d'obtenir une représentation graphique du labyrinthe en console */
void displayMaze(Maze& mazeToDisplay)
{
    int mazeLength = mazeToDisplay.size();
    int mazeHeight = mazeToDisplay[0].size();

    for (int y = 0; y < mazeHeight; y++)
    {
        std::cout << "\n";
        for (int x = 0; x < mazeLength; x++)
        {
            if (mazeToDisplay[x][y]->isTheGuyHere) 
            {
                std::cout << THE_GUY;
            }
            else if (mazeToDisplay[x][y]->isRunThrough) 
            {
                std::cout << PATH;
            }
            else 
            {        
                std::cout << mazeToDisplay[x][y]->content;
            }
        }
    }

    std::cout << "\n";
}