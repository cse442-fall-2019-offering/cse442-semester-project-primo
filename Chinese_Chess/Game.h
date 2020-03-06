#pragma once
#include "Piece.h"
#include <string>
#include <corecrt_wstring.h>


class Game
{
public:
	Game(Player player1, Player player2);
	~Game();

	//Board initialization
	void init_Board();

	//debug and test function
	void Game::print_Board();

	//getter function
	Player* getPlayer1();
	Player* getPlayer2();
	int getturns();
	vector<vector<Piece>> getBoard();

	//setter function
private:
	vector<vector<Piece>> Board;
	Player player1;
	Player player2;
	int turns;
};

