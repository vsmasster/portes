#ifndef judge_hpp
#define judge_hpp
#include <bits/stdc++.h>
#include "constants.hpp"
#include "checker.hpp"
#include "board.hpp"
#include "player.hpp"
using namespace std;

class Player;

class Judge{
	private:
		Board board;
		pair<int,int> dice;
		vector< pair<int,int> > last_moves;
		COLOR cur_player;
		Player* pl1_handler, *pl2_handler;
		vector< vector< pair<int,int> > >  generate_moves();
		bool ifEnd();
		
		
	public:
		Judge();
		
		void registerPlayers(Player* pl1, Player* pl2);
		bool isAlive();
		pair<int,int> rollDice();
		bool move(int from,int to,COLOR color);
		vector< pair<int,int> > getLastMoves();
		void log();
};

#endif
