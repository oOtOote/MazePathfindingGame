#ifndef MAZEINITIALIZER_HPP
#define MAZEINITIALIZER_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <memory>
#include "MyConstantValues.hpp"
#include "CellGenerator.hpp"
#include "MyStructs.hpp"

using Maze = std::deque<std::deque<std::unique_ptr<Cell>>>;
using Coordinates = std::vector<int>;

Coordinates initializeThePositionGuy(Maze& maze);
Maze initializeMaze();

#endif // !MAZEINITIALIZER_HPP