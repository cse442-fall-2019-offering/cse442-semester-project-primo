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

	int line;
	int row;
	int ini_line;
	int ini_row;
	
	int type;
	
	Player* player;
	


public:
	

	//movement function
	vector<pair<int, int>> aviliable_move(vector<vector<Piece>> Board);

	//setter function
	void set_line(int line);
	void set_row(int row);
	void set_ini_line(int line);
	void set_ini_row(int row);

	void set_type(int type);

	void set_player(Player* player);

	//getter function
	int get_line();
	int get_row();
	int get_ini_line();
	int get_ini_row();

	int get_type();

	Player* get_player();

private:
	vector<pair<int, int>> Kings_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Advisor_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Bishop_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Horse_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Chariots_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Cannon_move(vector<vector<Piece>> Board);
	vector<pair<int, int>> Soldier_move(vector<vector<Piece>> Board);
};


