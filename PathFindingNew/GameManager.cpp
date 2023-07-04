#include "gameManager.hpp"


/* permet de presenter le jeu en console au joueur */
void startingGame()
{
    cout << "BIENVENU DANS 'CHASSEUR DE FORTUNE' \n" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Dans ce jeu vous incarne 'The Guy' represente par son elegant avatar : " << THE_GUY << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Vous parcourrez un labyrinthe seme d'aucune embuche a part des murs " << WALL << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "dans le but de recupere un incroyable tresor dont voici la resplendissante representation : " << TREASURE << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Mais que contient donc ce tresor???" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "A vous de jouer pour le savoir! " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Pour controler les deplacement de the guy, utilisez les touches z q s d " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
}


/* demande au joueur une entrée clavier (parmi z,q,s,d) pour faire avancer the guy */
string askKeyboardEntry()
{
    string entry;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Veuillez envoyer l une des entrees claviers suivantes: z,q,s,d puis appuyez sur entree afin de deplacer 'the guy'" << endl;
    getline(cin, entry);
    cout << "cle entree: " << entry << endl;
    if (entry != "z" && entry != "q" && entry != "s" && entry != "d")
    {
        cout << "entree clavier invalide " << endl;
        askKeyboardEntry();
    }
    return entry;
}


/* interprète l'entrée clavier en direction où se déplacer */
direction interpretKeyboardEntry(string keyboardEntry)
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
        cout << "\ncle clavier non valide detectee. Le programme va faire n importe quoi prochainement." << endl;
    }

    return wantedDirection;
}


/* vérifier si la case où le joueur souhaite se déplacer est un mur */
bool checkForWall(deque<deque<string>> maze, vector<int> theGuyCoordinates, direction theGuyDirection)
{
    bool isWallAhead = false;

    switch (theGuyDirection)
    {
    case TOP:
        if (maze[theGuyCoordinates[0]][theGuyCoordinates[1] - 1] == WALL)
        {
            isWallAhead = true;
        }
        break;

    case RIGHT:
        if (maze[theGuyCoordinates[0] + 1][theGuyCoordinates[1]] == WALL)
        {
            isWallAhead = true;
        }
        break;

    case BELOW:
        if (maze[theGuyCoordinates[0]][theGuyCoordinates[1] + 1] == WALL)
        {
            isWallAhead = true;
        }
        break;

    case LEFT:
        if (maze[theGuyCoordinates[0] - 1][theGuyCoordinates[1]] == WALL)
        {
            isWallAhead = true;
        }
        break;
    }

    if (isWallAhead)
    {
        cout << "\n mais, vous allez dans le mur !" << endl;
    }

    return isWallAhead;
}