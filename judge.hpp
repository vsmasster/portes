#ifndef judge_h
#define judge_h
#include <bits/stdc++.h>
#include "board.hpp"
class Judge{
	private:
		Board board;
		int turn_num;
		vector< pair<int,int> > roll_results;
	public:
		Judge(){
			turn_num = 0;
			board.init();
		}
		bool isAlive();
		pair<int,int> rollDice();
		void log();
};

#endif
