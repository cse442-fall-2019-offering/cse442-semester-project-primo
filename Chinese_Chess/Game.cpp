#include "pch.h"
#include "Game.h"
#include <iostream>

Game::Game() {
}

Game::Game(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->init_Board();
	int turn = 0;
	this->move_flag = 0;
	this->aviliable_flag = 0;
}
Game::~Game() {

}

void Game::init_Board() {
	Player* player1 = this->player1;
	Player* player2 = this->player2;
	player1->set_ID(1);
	player2->set_ID(2);

	this->Board = vector<vector<Piece>>(10, vector<Piece>(9, Piece()));
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9; j++) {
			this->Board.at(i).at(j).set_line(i);
			this->Board.at(i).at(j).set_row(j);
			this->Board.at(i).at(j).set_ini_line(i);
			this->Board.at(i).at(j).set_ini_row(j);
			this->Board.at(i).at(j).set_type(no_piece);
			this->Board.at(i).at(j).set_player(NULL);
		}
	}

	//set the initial position for all pieces
	//line 0
	this->Board.at(0).at(0).set_type(Chariots);
	this->Board.at(0).at(0).set_player(player2);

	this->Board.at(0).at(1).set_type(Horse);
	this->Board.at(0).at(1).set_player(player2);

	this->Board.at(0).at(2).set_type(Bishop);
	this->Board.at(0).at(2).set_player(player2);

	this->Board.at(0).at(3).set_type(Advisor);
	this->Board.at(0).at(3).set_player(player2);

	this->Board.at(0).at(4).set_type(King);
	this->Board.at(0).at(4).set_player(player2);

	this->Board.at(0).at(5).set_type(Advisor);
	this->Board.at(0).at(5).set_player(player2);

	this->Board.at(0).at(6).set_type(Bishop);
	this->Board.at(0).at(6).set_player(player2);

	this->Board.at(0).at(7).set_type(Horse);
	this->Board.at(0).at(7).set_player(player2);

	this->Board.at(0).at(8).set_type(Chariots);
	this->Board.at(0).at(8).set_player(player2);

	//line 2
	this->Board.at(2).at(1).set_type(Cannon);
	this->Board.at(2).at(1).set_player(player2);

	this->Board.at(2).at(7).set_type(Cannon);
	this->Board.at(2).at(7).set_player(player2);

	//line 3
	this->Board.at(3).at(0).set_type(Soldier);
	this->Board.at(3).at(0).set_player(player2);

	this->Board.at(3).at(2).set_type(Soldier);
	this->Board.at(3).at(2).set_player(player2);

	this->Board.at(3).at(4).set_type(Soldier);
	this->Board.at(3).at(4).set_player(player2);

	this->Board.at(3).at(6).set_type(Soldier);
	this->Board.at(3).at(6).set_player(player2);

	this->Board.at(3).at(8).set_type(Soldier);
	this->Board.at(3).at(8).set_player(player2);

	//line 6
	this->Board.at(6).at(0).set_type(Soldier);
	this->Board.at(6).at(0).set_player(player1);

	this->Board.at(6).at(2).set_type(Soldier);
	this->Board.at(6).at(2).set_player(player1);

	this->Board.at(6).at(4).set_type(Soldier);
	this->Board.at(6).at(4).set_player(player1);

	this->Board.at(6).at(6).set_type(Soldier);
	this->Board.at(6).at(6).set_player(player1);

	this->Board.at(6).at(8).set_type(Soldier);
	this->Board.at(6).at(8).set_player(player1);

	//line 7
	this->Board.at(7).at(1).set_type(Cannon);
	this->Board.at(7).at(1).set_player(player1);

	this->Board.at(7).at(7).set_type(Cannon);
	this->Board.at(7).at(7).set_player(player1);

	//line 9
	this->Board.at(9).at(0).set_type(Chariots);
	this->Board.at(9).at(0).set_player(player1);

	this->Board.at(9).at(1).set_type(Horse);
	this->Board.at(9).at(1).set_player(player1);

	this->Board.at(9).at(2).set_type(Bishop);
	this->Board.at(9).at(2).set_player(player1);

	this->Board.at(9).at(3).set_type(Advisor);
	this->Board.at(9).at(3).set_player(player1);

	this->Board.at(9).at(4).set_type(King);
	this->Board.at(9).at(4).set_player(player1);

	this->Board.at(9).at(5).set_type(Advisor);
	this->Board.at(9).at(5).set_player(player1);

	this->Board.at(9).at(6).set_type(Bishop);
	this->Board.at(9).at(6).set_player(player1);

	this->Board.at(9).at(7).set_type(Horse);
	this->Board.at(9).at(7).set_player(player1);

	this->Board.at(9).at(8).set_type(Chariots);
	this->Board.at(9).at(8).set_player(player1);

}

void Game::print_Board() {
	vector<vector<Piece>> board = this->Board;
	std::string out;
	std::string pout;
	vector<pair<int, int>> aviliable;
	int type = 0;
	int id = 0;
	//king test
	/*board.at(1).at(3).set_type(King);
	board.at(1).at(3).set_player(board.at(0).at(3).get_player());
	board.at(3).at(4) = board.at(3).at(5);
	board.at(6).at(4) = board.at(6).at(5);*/
	
	//advisor test
	/*board.at(1).at(4) = board.at(0).at(3);
	board.at(1).at(4).set_line(1);
	board.at(1).at(4).set_row(4);*/

	//bishop test
	//board.at(1).at(1) = board.at(0).at(0); //block test
	/*board.at(2).at(0) = board.at(0).at(0); //take test
	board.at(2).at(0).set_line(2);
	board.at(2).at(0).set_row(0);
	board.at(2).at(0).set_player(board.at(9).at(0).get_player());*/
	//aviliable = board.at(0).at(2).aviliable_move(board);

	//horse test
	//aviliable = board.at(0).at(1).aviliable_move(board);

	//Chariots test
	//aviliable = board.at(0).at(0).aviliable_move(board);

	//Cannon test
	//aviliable = board.at(2).at(1).aviliable_move(board);
	//board.at(2).at(0) = board.at(2).at(1);
	//board.at(2).at(0).set_line(2);
	//board.at(2).at(0).set_row(0);
	//aviliable = board.at(2).at(0).aviliable_move(board);

	//Soilder test
	//aviliable = board.at(3).at(0).aviliable_move(board);	//start case for p2
	//aviliable = board.at(6).at(0).aviliable_move(board);	//start case for p1
	/*board.at(5).at(0) = board.at(3).at(0);				//passed the river case
	board.at(5).at(0).set_line(5);
	board.at(5).at(0).set_row(0);
	board.at(6).at(0).set_player(&this->player2);*/

	aviliable = board.at(6).at(0).aviliable_move(board);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			Piece p = board.at(i).at(j);
			type = p.get_type();
			if (p.get_player() == NULL) pout.push_back('0');
			else {
				id = p.get_player()->get_ID();
				pout.push_back(id + '0');
			}
			
			out.push_back(type + '0');
		}
		pout.push_back('\n');
		out.push_back('\n');
	}

	
}

Player* Game::getPlayer1() {
	return this->player1;
}
Player* Game::getPlayer2() {
	return this->player2;
}
int Game::getturns() {
	return this->turns;
}
vector<vector<Piece>> Game::getBoard() {
	return this->Board;
}
