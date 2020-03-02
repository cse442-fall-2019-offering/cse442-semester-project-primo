#pragma once
#include <vector>

class Board
{
public:
	Board();
	~Board();
	std::vector<std::vector<int>> getBoard();

private:
	std::vector<std::vector<int>> board;


};

