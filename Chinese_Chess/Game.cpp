#include "pch.h"
#include "Game.h"

Game::Game() {
}

Game::Game(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->init_Board();
	srand((unsigned)time(NULL));
	int turn = rand() % 2;
	turn = 0;
	if (turn == 0) this->turns = player1;
	else this->turns = player2;
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
Player* Game::getturns() {
	return this->turns;
}
vector<vector<Piece>> Game::getBoard() {
	return this->Board;
}

void Game::setboard(int x, int y, Piece piece) {
	this->Board.at(x).at(y) = piece;
}

void Game::switch_turn() {
	if (this->turns == this->player1) this->turns = this->player2;
	else this->turns = this->player1;
}

int Game::check_win() {
	int k1 = 0;
	int k2 = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			Piece piece = this->Board.at(i).at(j);
			if (piece.get_type() == King) {
				if (piece.get_player() == this->player1) k1 = 1;
				else k2 = 1;
			}
		}
	}
	if (k1 == 0 && k2 == 1) return 2;
	if (k2 == 0 && k1 == 1) return 1;
	else return 0;
}

void Game::move() {
	Player* curplayer = this->getturns();
	if (curplayer != this->player1) {
		switch (curplayer->get_type()) {
			case Easy_AI:
				easymove();
//				Sleep(1000);
				this->switch_turn();
				break;
			case Medium_AI:
				break;
			case Hard_AI:
				break;
			default:
				break;
		}
		
	}
}

void Game::easymove() {
	Player* curplayer = this->turns;
	vector<vector<Piece>> board = this->Board;
	vector<pair<pair<int, int>, pair<int, int>>> total_aviliable;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			Piece p = board.at(i).at(j);
			pair<int, int> select(i, j);
			vector<pair<int, int>> aviliable = p.aviliable_move(board, curplayer);
			for (int k = 0; k < aviliable.size(); k++) {
				pair<int, int> destination = aviliable.at(k);
				pair<pair<int, int>, pair<int, int>> p_step(select, destination);
				total_aviliable.push_back(p_step);
			}
		}
	}
	int size = total_aviliable.size();
	srand((unsigned)time(NULL));
	int rand_step = rand() % size;
	pair<int, int> destination = total_aviliable.at(rand_step).second;
	pair<int, int> empty = total_aviliable.at(rand_step).first;

	int x = destination.first;
	int y = destination.second;
	Piece move = Piece();
	move.copy(board.at(empty.first).at(empty.second));
	move.set_line(x);
	move.set_row(y);

	this->setboard(x, y, move);

	Piece null_p = Piece();
	null_p.set_line(empty.first);
	null_p.set_row(empty.second);
	null_p.set_ini_line(empty.first);
	null_p.set_ini_row(empty.second);
	null_p.set_player(NULL);
	null_p.set_type(no_piece);

	this->Board.at(empty.first).at(empty.second) = null_p;
	this->setboard(empty.first, empty.second, null_p);
}