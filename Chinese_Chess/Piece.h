#pragma once
#include <vector>
#include <utility> 
#include "Player.h"

#define no_piece	0
#define King		1
#define Advisor		2
#define Bishop		3
#define Horse		4
#define Chariots	5
#define Cannon		6
#define Soldier		7
using namespace std;

class Piece
{
private:
	int type;
	Player* player;
	int line;
	int row;

public:
	//setter function
	void set_type(int type);
	void set_line(int line);
	void set_row(int row);
	void set_player(Player* player);

	//getter function
	int get_type();
	int get_line();
	int get_row();
	Player* get_player();

	//movement function
	vector<pair<int, int>> aviliable_move(vector<vector<Piece>> Board);

private:
	vector<pair<int, int>> Kings_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Advisor_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Bishop_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Horse_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Chariots_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Cannon_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Soldier_move(vector<vector<Piece>> Board);
};


