#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#define human 1
#define Easy_AI 2
#define Medium_AI 3
#define Hard_AI 4


class Player
{
public:
	Player();
	~Player();
	Player(int ID, int type);
	void set_ID(int ID);
	int get_ID();
	int get_type();

private:
	int ID;
	int type;


};

#endif