#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>
#include "MyEnums.hpp"
#include "MyConstantValues.hpp"
#include "MyStructs.hpp"

using Maze = std::deque<std::deque<std::unique_ptr<Cell>>>;
using Coordinates = std::vector<int>;

void startingGame();
std::string askKeyboardEntry();
direction interpretKeyboardEntry(std::string keyboardEntry);
bool checkForWall(const Maze& maze, const Coordinates theGuyCoordinates, direction theGuyDirection);

#endif //!GAMEMANAGER_HPP
