#include "pch.h"
#include "Kings.h"

Kings::Kings() : Piece(line, row, player) {
	this->line = line;
	this->row = row;
	this->player = player;
	this->type = kings;
}