#include "mazeDisplayer.hpp"


/* permet d'obtenir une représentation graphique du labyrinthe en console */
void displayMaze(deque<deque<string>>& mazeToDisplay)
{
    int mazeLength = mazeToDisplay.size();
    int mazeHeight = mazeToDisplay[0].size();

    for (int y = 0; y < mazeHeight; y++)
    {
        cout << "\n";
        for (int x = 0; x < mazeLength; x++)
        {
            cout << mazeToDisplay[x][y];
        }
    }

    cout << "\n";
}