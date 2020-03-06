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
	int line = this->line;
	int row = this->row;

	//upper right conner case
	if ((line == 0 && row == 3) || (line == 7 && row == 3)) {
		int newline = line + 1;
		int newrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	//upper left case
	else if ((line == 0 && row == 5) || (line == 7 && row == 5)) {
		int newline = line + 1;
		int newrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	//middle case
	else if ((line == 1 && row == 4) || (line == 8 && row == 4)) {
		int newline = line - 1;
		int newrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		newline = line - 1;
		newrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		newline = line + 1;
		newrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		newline = line + 1;
		newrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	else if ((line == 2 && row == 3) || (line == 9 && row == 3)) {
		int newline = line - 1;
		int newrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	else if ((line == 2 && row == 5) || (line == 9 && row == 5)) {
		int newline = line - 1;
		int newrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type()) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	else;

	return aviliable;
}

vector<pair<int, int>> Piece::Bishop_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;
	int l = this->line;
	int r = this->row;
	//upper case
	if ((l == 0 && r == 2) || (l == 0 && r == 6) || (l == 5 && r == 2) || (l == 5 && r == 6)) {
		//move to down right
		int newline = line + 2;
		int newrow = row + 2;
		int pathline = line + 1;
		int pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to down left
		newline = line + 2;
		newrow = row -2;
		pathline = line + 1;
		pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}

	//lower case
	else if ((l == 4 && r == 2) || (l == 4 && r == 6) || (l == 9 && r == 2) || (l == 9 && r == 6)) {
		//move to up right
		int newline = line - 2;
		int newrow = row + 2;
		int pathline = line - 1;
		int pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to up left
		newline = line - 2;
		newrow = row - 2;
		pathline = line - 1;
		pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}

	//left most case
	else if ((l == 2 && r == 0) || (l == 7 && r == 0)) {
		//move to up right
		int newline = line - 2;
		int newrow = row + 2;
		int pathline = line - 1;
		int pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to down right
		newline = line + 2;
		newrow = row + 2;
		pathline = line + 1;
		pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}

	//right most case
	else if ((l == 2 && r == 8) || (l == 7 && r == 8)) {
		//move to up left
		int newline = line - 2;
		int newrow = row - 2;
		int pathline = line - 1;
		int pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to down left
		newline = line + 2;
		newrow = row - 2;
		pathline = line + 1;
		pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type()
			== no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}

	//middle case
	else if ((l == 2 && r == 4) || (l == 7 && r == 4)) {
		//move to up left
		int newline = line - 2;
		int newrow = row - 2;
		int pathline = line - 1;
		int pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to up right
		newline = line - 2;
		newrow = row + 2;
		pathline = line - 1;
		pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
		//move to down left
		newline = line + 2;
		newrow = row - 2;
		pathline = line + 1;
		pathrow = row - 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}

		//move to down right
		newline = line + 2;
		newrow = row + 2;
		pathline = line + 1;
		pathrow = row + 1;
		if (this->type != Board.at(newline).at(newrow).get_type() && Board.at(pathline).at(pathrow).get_type() == no_piece) {
			pair<int, int> pair(newline, newrow);
			aviliable.push_back(pair);
		}
	}
	else;

	return aviliable;
}

vector<pair<int, int>> Piece::Horse_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;
	int l = this->line;
	int r = this->row;
	int nl = 0;
	int nr = 0;

	//move up
	if (l - 2 >= 0) {
		if (Board.at(l - 1).at(r).get_type() == no_piece) {
			
			//move up left
			nl = l - 2;
			nr = r - 1;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}
			
			//move up right
			nl = l - 2;
			nr = r + 1;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}
		}
	}

	//move down
	if (l + 2 <= 9) {
		if (Board.at(l + 1).at(r).get_type() == no_piece) {
			//move down left
			nl = l + 2;
			nr = r - 1;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}

			//move down right
			nl = l + 2;
			nr = r + 1;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}
		}
	}

	//move left
	if (r - 2 >= 0) {
		if (Board.at(l).at(r - 1).get_type() == no_piece) {
			//move upper left
			nl = l - 1;
			nr = r - 2;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}

			//move lower right
			nl = l + 1;
			nr = r - 2;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}
		}
	}
	//move right
	if (r + 2 <= 8) {
		if (Board.at(l).at(r + 1).get_type() == no_piece) {
			//move upper right
			nl = l - 1;
			nr = r + 2;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}

			//move lower left
			nl = l + 1;
			nr = r + 2;
			if (Board.at(nl).at(nr).get_player() != this->get_player()) {
				pair<int, int> pair(nl, nr);
				aviliable.push_back(pair);
			}
		}
	}
	return aviliable;
}

vector<pair<int, int>> Piece::Chariots_move(vector<vector<Piece>> Board) {
	vector<pair<int, int>> aviliable;
	int l = this->line;
	int r = this->row;
	int nl, nr = 0;

	//move up
	nl = l - 1;
	nr = r;
	while (nl >= 0) {
		if (Board.at(nl).at(nr).get_type() != no_piece) break;
		pair<int, int> pair(nl, nr);
		aviliable.push_back(pair);
		nl--;
	}
	//move down
	nl = l + 1;
	nr = r;
	while (nl <= 9) {
		if (Board.at(nl).at(nr).get_type() != no_piece) break;
		pair<int, int> pair(nl, nr);
		aviliable.push_back(pair);
		nl++;
	}
	//move left
	nl = l;
	nr = r - 1;
	while (nr >= 0) {
		if (Board.at(nl).at(nr).get_type() != no_piece) break;
		pair<int, int> pair(nl, nr);
		aviliable.push_back(pair);
		nl--;
	}
	//move right
	nl = l;
	nr = r + 1;
	while (nr <= 8) {
		if (Board.at(nl).at(nr).get_type() != no_piece) break;
		pair<int, int> pair(nl, nr);
		aviliable.push_back(pair);
		nl++;
	}
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
