#ifndef MAZEDISPLAYER_HPP
#define MAZEDISPLAYER_HPP

#include <iostream>
#include <deque>
#include <memory>
#include "MyStructs.hpp"
#include "MyConstantValues.hpp"

using Maze = std::deque<std::deque<std::unique_ptr<Cell>>>;

void displayMaze(Maze& mazeToDisplay);

#endif // !MAZEDISPLAYER_HPP