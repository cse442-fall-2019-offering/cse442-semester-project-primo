#include "pch.h"
#include "Piece.h"


<<<<<<< HEAD
<<<<<<< HEAD
piece::piece(char clan, char type, char x, char y) {
	this->clan = clan;
	this->type = type;
	this->dead = false;
	this->xposition = x;
	this->yposition = y;
}

piece::~piece()
{

}
=======
vector<pair<int, int>> aviliable_move(int type);
vector<pair<int, int>> Kings_move(int type);
vector<pair<int, int>> Advisor_move(int type);
vector<pair<int, int>> Bishop_move(int type);
vector<pair<int, int>> Horse_move(int type);
vector<pair<int, int>> Chariots_move(int type);
vector<pair<int, int>> Cannon_move(int type);
vector<pair<int, int>> Soldier_move(int type);
=======
vector<pair<int, int>> Piece::aviliable_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;
	switch (this->type) {
	case no_piece:
		return aviliable;
		break;

	case King:
		return this->Kings_move(Board);
		break;

	case Advisor:
		return this->Advisor_move(Board);
		break;

	case Bishop:
		return this->Bishop_move(Board);
		break;

	case Horse:
		return this->Horse_move(Board);
		break;

	case Chariots:
		return this->Chariots_move(Board);
		break;

	case Cannon:
		return this->Cannon_move(Board);
		break;

	case Soldier:
		return this->Soldier_move(Board);
		break;

	default:
		return aviliable;
		break;
	}
	
	return aviliable;
}

vector<pair<int, int>> Piece::Kings_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;
	Player* player = this->player;
	int line = this->line;
	int row = this->row;

	int ulb, llb;	//represent upper line bound, lower line bound
	int	lrb = 3;	//left row bound
	int rrb = 5;	//right row bound

	//initialize line bounds
	if (line <= 4) {
		ulb = 0;
		llb = 2;
	}
	else {
		ulb = 7;
		llb = 9;
	}

	int oprow;				//get the opponent's kings row location
	int forbidrow = -1;		//this handles to kings can not face each other

	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 6; j++) {
			if (Board.at(i).at(j).get_type() == King) {
				if (i != line) oprow = j;
			}
		}
	}

	for (int i = 7; i < 10; i++) {
		for (int j = 3; j < 6; j++) {
			if (Board.at(i).at(j).get_type() == King) {
				if (i != line) oprow = j;
			}
		}
	}

	//check if there exist a forbid row
	for (int i = 0; i < 10; i++) {
		if (Board.at(i).at(oprow).get_type() != no_piece && Board.at(i).at(oprow).get_type() != King) break;
		if (i == 9) forbidrow = oprow;
	}

	int newline, newrow;

	//move up;
	newline = line - 1;
	newrow = row;
	if (newline >= ulb) {
		if (Board.at(newline).at(newrow).get_player() != player) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
		
	}

	//move down
	newline = line + 1;
	newrow = row;
	if (newline <= llb) {
		if (Board.at(newline).at(newrow).get_player() != player) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
		
	}

	//move left
	newline = line;
	newrow = row - 1;
	if (newrow >= lrb) {
		int a = 5;
		if (Board.at(newline).at(newrow).get_player() != player && newrow != forbidrow) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
		
	}

	//move right
	newline = line;
	newrow = row + 1;
	if (newrow <= rrb) {
		if (Board.at(newline).at(newrow).get_player() != player && newrow != forbidrow) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}

	return aviliable;
}

vector<pair<int, int>> Piece::Advisor_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
vector<pair<int, int>> Piece::Bishop_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
vector<pair<int, int>> Piece::Horse_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
vector<pair<int, int>> Piece::Chariots_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
vector<pair<int, int>> Piece::Cannon_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
vector<pair<int, int>> Piece::Soldier_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;

	return aviliable;
}
>>>>>>> King movement set up

void Piece::set_type(int type) {
	this->type = type;
}
void Piece::set_line(int line) {
	this->line = line;
}
void Piece::set_row(int row) {
	this->row = row;
}
void Piece::set_player(Player* player) {
	this->player = player;
}

int Piece::get_type() {
	return this->type;
}
int Piece::get_line() {
	return this->line;
}
int Piece::get_row() {
	return this->row;
}
Player* Piece::get_player() {
	return this->player;
}
>>>>>>> task 45 without a new branch
