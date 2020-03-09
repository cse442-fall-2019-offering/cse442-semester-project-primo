#include "pch.h"
#include "Piece.h"


piece::piece(char clan, char type, char x, char y) {
	this->clan = clan;
	this->type = type;
	this->dead = false;
	this->xposition = x;
	this->yposition = y;
}

piece::~piece()
{

}
