#include "CellGenerator.hpp"


/* génère aléatoirement le contenu d'une cellule */
std::string generateRandomCellContent()
{
    int randomNumber = rand() % 4; // va servir a générer un contenu aléatoire aux cellules
    std::string newCellContent = WALL;

    switch (randomNumber) 
    {
    case 0:
        newCellContent = WALL;
        break;

    case 1:
    case 2:
        newCellContent = DIRT;
        break;

        newCellContent = DIRT;
        break;

    case 3:
        newCellContent = MUD;
        break;

    default:
        newCellContent = "error";
        std::cout << "\nechec dans la generation du contenu de la cellule";
        break;
    }

    return newCellContent;
}