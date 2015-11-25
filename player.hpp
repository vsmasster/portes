#ifndef player_hpp
#define player_hpp
#include <bits/stdc++.h>
#include "ai.hpp"
#include "judge.hpp"
using namespace std;

class Player{
private:
	bool ai;
	//AI ai_handler;
	Judge* judge;
	string name;
	
	public:
		Player(Judge* _judge,bool _ai);
		std::string getName();
		void turn();
};

#endif
