#ifndef MAZEINITIALIZER_H
#define MAZEINITIALIZER_H

#include <iostream>
#include <deque>
#include <vector>
#include "ConstantValues.hpp"
#include "CellGenerator.hpp"

using namespace std;


vector<int> initializeThePositionGuy(deque<deque<string>>& maze);
deque<deque<string>> initializeMaze();

#endif 