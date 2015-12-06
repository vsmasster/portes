#ifndef ai_hpp
#define ai_hpp
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "player.hpp"
using namespace std;

class Judge;

class AI{
	private:
		Judge* judge;
		COLOR color;
		void pass(int from, int to);
		
	public:
		AI(Judge* j,COLOR c);
		string getName();
		void turn(Board board);
};

#endif
