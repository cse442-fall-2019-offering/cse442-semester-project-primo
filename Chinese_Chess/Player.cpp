#include "pch.h"
#include "Player.h"


Player::Player() {

}
Player::~Player() {

}
Player::Player(int ID, int type) {
	this->ID = ID;
	this->type = type;
}

void Player::set_ID(int ID) {
	this->ID = ID;
}

int Player::get_ID() {
	return this->ID;
}

int Player::get_type() {
	return this->type;
}

/*void Player::move(vector<vector<Piece>> board) {
	/*vector<pair<pair<int, int>, pair<int, int>>> all;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			Piece p = board.at(i).at(j);
			vector<pair<int, int>> aviliable = p.aviliable_move(board, this);
		}
	}
}*/
