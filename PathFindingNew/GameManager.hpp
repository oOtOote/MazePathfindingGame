#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <chrono>
#include <thread>
#include "MyEnums.hpp";
#include "ConstantValues.hpp"

using namespace std;


void startingGame();
string askKeyboardEntry();
direction interpretKeyboardEntry(string keyboardEntry);
bool checkForWall(deque<deque<string>> maze, vector<int> theGuyCoordinates, direction theGuyDirection);

#endif