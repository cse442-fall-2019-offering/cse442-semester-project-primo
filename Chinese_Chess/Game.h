#pragma once
#include "Piece.h"
#include <string>
#include <corecrt_wstring.h>

class Game
{
public:
	Game();
	Game(Player* player1, Player* player2);
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

	int aviliable_flag;
	int move_flag;

	//setter function
	void setboard(int x, int y, Piece piece);
private:
	vector<vector<Piece>> Board;
	Player* player1;
	Player* player2;
	int turns;
};

