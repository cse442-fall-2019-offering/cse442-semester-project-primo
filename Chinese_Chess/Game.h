#pragma once
#include "Board.h"
#include "Player.h"

class Game
{
public:
	Game(Board board, Player player1, Player player2);
	~Game();
private:
	Board Board;
	Player player1;
	Player player2;
	int turns;
};

