#ifndef judge_hpp
#define judge_hpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
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
		bool ifEnd();
		bool correct_move(pair<int, int> move, COLOR color);
		
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
