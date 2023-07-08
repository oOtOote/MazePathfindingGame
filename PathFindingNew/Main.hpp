#ifndef MAIN_HPP
#define MAIN_HPP

#include "MazeDisplayer.hpp"
#include "MazeInitializer.hpp"
#include "CellGenerator.hpp" 
#include "MovementManager.hpp"
#include "GameManager.hpp"
#include "MyConstantValues.hpp"
#include "MyEnums.hpp"

using Maze = std::deque<std::deque<std::unique_ptr<Cell>>>;
using Coordinates = std::vector<int>;

int main();

#endif // !MAIN_HPP