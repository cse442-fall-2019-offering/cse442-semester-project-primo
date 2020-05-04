#pragma once
#ifndef GAME_H
#define GAME_H

#include "Piece.h"
#include <string>
#include <corecrt_wstring.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <dos.h>
#include <Windows.h>

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

	

	int aviliable_flag;
	int set_flag;

	void switch_turn();

	void move();


	//getter function
	Player* getPlayer1();
	Player* getPlayer2();
	Player* getturns();
	vector<vector<Piece>> getBoard();

	//setter function
	void setboard(int x, int y, Piece piece);

	int check_win();

private:
	vector<vector<Piece>> Board;
	Player* player1;
	Player* player2;
	Player* turns;
	void easy_move();
	void level_move(float bias);
	vector<pair<pair<int, int>, pair<int, int>>> all_movement();
	vector<pair<int, int>> most_agressive();
	vector<pair<int, int>> second_agressive();
	void make_move(pair<int, int> start, pair<int, int> dest);
	bool contain_pair(vector<pair<int, int>> list, pair<int, int> node);
};

#endif