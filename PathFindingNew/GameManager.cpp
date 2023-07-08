#include "gameManager.hpp"


/* permet de presenter le jeu en console au joueur */
void startingGame()
{
    std::cout << "BIENVENU DANS 'CHASSEUR DE FORTUNE' \n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Dans ce jeu vous incarne 'The Guy' represente par son elegant avatar : " << THE_GUY << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Vous parcourrez un labyrinthe seme d'aucune embuche a part des murs " << WALL << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "dans le but de recupere un incroyable tresor dont voici la resplendissante representation : " << TREASURE << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Mais que contient donc ce tresor???" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "A vous de jouer pour le savoir! " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Pour controler les deplacement de the guy, utilisez les touches z q s d " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


/* demande au joueur une entrée clavier (parmi z,q,s,d) pour faire avancer the guy */
std::string askKeyboardEntry()
{
    std::string entry;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Veuillez envoyer l une des entrees claviers suivantes: z,q,s,d puis appuyez sur entree afin de deplacer 'the guy'" << std::endl;
    std::getline(std::cin, entry);
    std::cout << "cle entree: " << entry << std::endl;
    if (entry != "z" && entry != "q" && entry != "s" && entry != "d")
    {
        std::cout << "entree clavier invalide " << std::endl;
        askKeyboardEntry();
    }
    return entry;
}


/* interprète l'entrée clavier en direction où se déplacer */
direction interpretKeyboardEntry(std::string keyboardEntry)
{
    direction wantedDirection = TOP;
    if (keyboardEntry == "z") {
        wantedDirection = TOP;
    }
    else if (keyboardEntry == "q")
    {
        wantedDirection = LEFT;
    }
    else if (keyboardEntry == "d")
    {
        wantedDirection = RIGHT;
    }
    else if (keyboardEntry == "s")
    {
        wantedDirection = BELOW;
    }
    else
    {
        std::cout << "\ncle clavier non valide detectee. Le programme va faire n importe quoi prochainement." << std::endl;
    }

    return wantedDirection;
}


/* vérifier si la case où le joueur souhaite se déplacer est un mur */
bool checkForWall(const Maze& maze, const Coordinates theGuyCoordinates, direction theGuyDirection)
{
    bool isWallAhead = false;

    switch (theGuyDirection)
    {
    case TOP:
        if (maze[theGuyCoordinates[0]][theGuyCoordinates[1] - 1]->content == WALL)
        {
            isWallAhead = true;
        }
        break;

    case RIGHT:
        if (maze[theGuyCoordinates[0] + 1][theGuyCoordinates[1]]->content == WALL)
        {
            isWallAhead = true;
        }
        break;

    case BELOW:
        if (maze[theGuyCoordinates[0]][theGuyCoordinates[1] + 1]->content == WALL)
        {
            isWallAhead = true;
        }
        break;

    case LEFT:
        if (maze[theGuyCoordinates[0] - 1][theGuyCoordinates[1]]->content == WALL)
        {
            isWallAhead = true;
        }
        break;
    }

    if (isWallAhead)
    {
        std::cout << "\n mais, vous allez dans le mur !" << std::endl;
    }

    return isWallAhead;
}