#include "pch.h"
#include "Board.h"

Board::Board() {
	this -> board = std::vector<std::vector<int>>(10, std::vector<int>(9, 0));
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9; j++) {
			this->board.at(i).at(j) = 0;
		}
	}
}

Board::~Board() {

}

std::vector<std::vector<int>>  Board::getBoard() {
	return this->board;
}