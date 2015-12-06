#ifndef player_hpp
#define player_hpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
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
		COLOR color;
	
	public:
		Player(Judge* _judge,bool _ai,COLOR color);
		string getName();
		void turn(Board board);
};

#endif
