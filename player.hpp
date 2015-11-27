#ifndef player_hpp
#define player_hpp
#include <bits/stdc++.h>
#include "constants.hpp"
#include "checker.hpp"
#include "board.hpp"
#include "judge.hpp"
#include "ai.hpp"
using namespace std;

class AI;
class Judge;

class Player{
	private:
		bool ai;
		AI* ai_handler;
		Judge* judge;
		string name;
		Board board;
	
	public:
		Player(Judge* _judge,bool _ai,COLOR color);
		std::string getName();
		void turn();
};

#endif
