#ifndef MYSTRUCTS_HPP
#define MYSTRUCTS_HPP

#include <string>
#include "MyConstantValues.hpp"

/* chaque cellule du tableau du labyrinthe contiens une struct Cell. Cette struct centralise les informations sur les propriétés de la cellule */
struct Cell 
{
	std::string content;
	bool isTheGuyHere;
	bool isRunThrough;

	Cell(std::string _content, bool _isTheGuyHere, bool _isRunThrough) : content(_content), isTheGuyHere(_isTheGuyHere), isRunThrough(_isRunThrough) {}
};

#endif // MYSTRUCTS_HPP