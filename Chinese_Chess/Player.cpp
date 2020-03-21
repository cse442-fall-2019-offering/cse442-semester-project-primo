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
