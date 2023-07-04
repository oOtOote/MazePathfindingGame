#ifndef MOVEMENTMANAGER_H
#define MOVEMENTMANAGER_H

#include <iostream>
#include <deque>
#include <vector>
#include "CellGenerator.hpp"
#include "MyEnums.hpp"
#include "ConstantValues.hpp"

using namespace std;


void moveTheGuy(deque<deque<string>>& maze, vector<int>& theGuyCoordinates, direction theGuyDirection, bool isNewLineAdded);
bool checkIfNewLineShouldBeAdded(deque<deque<string>> maze, vector<int> theGuyCoordinates, direction moveDirection);
void addNewLine(deque<deque<string>>& maze, direction newLinePosition);
void manageTheGuyMovement(deque<deque<string>>& maze, vector<int>& theGuyCoordinates, direction moveDirection);

#endif