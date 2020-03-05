#pragma once

#define human 1
#define random_AI 2
#define Q_AI 3

class Player
{
public:
	Player();
	~Player();
	Player(int ID, int type);
	void set_ID(int ID);
	int get_ID();
private:
	int ID;
	int type;


};

