#ifndef ai_hpp
#define ai_hpp
#include <bits/stdc++.h>
#include "player.hpp"
using namespace std;

class Judge;

class AI{
	private:
		Judge* judge;
		Board board;
		COLOR color;
		void pass(int from, int to);
		
	public:
		AI(Judge* j,COLOR c);
		string getName();
		void turn();
};

#endif
