#include "pch.h"
#include "Piece.h"


vector<pair<int, int>> aviliable_move(int type);
vector<pair<int, int>> Kings_move(int type);
vector<pair<int, int>> Advisor_move(int type);
vector<pair<int, int>> Bishop_move(int type);
vector<pair<int, int>> Horse_move(int type);
vector<pair<int, int>> Chariots_move(int type);
vector<pair<int, int>> Cannon_move(int type);
vector<pair<int, int>> Soldier_move(int type);

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