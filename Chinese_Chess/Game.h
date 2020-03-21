#pragma once
#include "Player.h"

class Game
{
public:
	Game(Player player1, Player player2);
	~Game();
private:
	Player player1;
	Player player2;
	int turns;
};

