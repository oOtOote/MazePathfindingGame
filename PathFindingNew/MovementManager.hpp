#ifndef MOVEMENTMANAGER_HPP
#define MOVEMENTMANAGER_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <memory>
#include "CellGenerator.hpp"
#include "MyEnums.hpp"
#include "MyStructs.hpp"
#include "MyConstantValues.hpp"

using Maze = std::deque<std::deque<std::unique_ptr<Cell>>>;
using Coordinates = std::vector<int>;


void moveTheGuy(Maze& maze, Coordinates& theGuyCoordinates, direction theGuyDirection, bool isNewLineAdded);
bool checkIfNewLineShouldBeAdded(const Maze& maze, const Coordinates& theGuyCoordinates, direction moveDirection);
void addNewLine(Maze& maze, direction newLinePosition);
void manageTheGuyMovement(Maze& maze, Coordinates& theGuyCoordinates, direction moveDirection);

#endif // !MOVEMENTMANAGER_HPP