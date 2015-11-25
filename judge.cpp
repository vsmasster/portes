#include "judge.hpp"

pair<int,int> Judge::rollDice(){
	int a = random() % 6 + 1;
	int b = random() % 6 + 1;
	roll_results.push_back(make_pair(a,b));
	return make_pair(a,b);
}

bool Judge::isAlive(){
	return ++turn_num < 10;
}

void Judge::log(){
	cout<<"Player 1 throws: "<<roll_results[0].first<<" "<<roll_results[0].second<<endl;
	cout<<"Player 2 throws: "<<roll_results[1].first<<" "<<roll_results[1].second<<endl;
	roll_results.clear();
}

/*	
	if(bar[color].size() == 0)return NO_CHEKCERS_IN_BAR;
		if(fields[to].size() > 1 && fields[to][0].color != color)return MOVE_TO_WRONG_FIELD;
		if(fields[to].size() == 1 && fields[to][0].color != color){
			bar[!color].push_back(fields[to][0]);
			fields[to].pop_back();
			fields[to].push_back(*(--bar[color].end()));
			bar[color].pop_back();
			return CKECHER_KICKED;
		}
		
		fields[to].push_back(*(--bar[color].end()));
		bar[color].pop_back();
		return CORRECT_MOVE;
	}
	
	if(to == OFF_FIELD){ //move checker off the board
		int beg = color == 0 ? WHITE_BASE_BEGIN : BLACK_BASE_BEGIN;
		int end = color == 0 ? WHITE_BASE_END : BLACK_BASE_END;
		
		int sum = 0;
		for(int i=beg;i<=end;i++)
			if(fields[i].size() != 0 && fields[i][0].color == color)
				sum += fields[i].size();
				
		if(sum + ch_off[color] != 15)return CHECKERS_NOT_IN_BASE;
		
		
	}
	
	if(from != BAR_FIELD && bar[color].size() != 0)return CHECKERS_IN_BAR;
	if(from > 24 || from < 0 || fields[from].size() == 0 || fields[from][0].color != color)return MOVE_FROM_WRONG_FIELD;
	if(to > 24 || to < 0 || (fields[to].size() > 1 && fields[to][0].color != color))return MOVE_TO_WRONG_FIELD;

	
	if(fields[to].size() == 1 && fields[to][0].color != color){
		bar[!color].push_back(fields[to][0]);
		fields[to].pop_back();
		fields[to].push_back(*(--fields[from].end()));
		fields[from].pop_back();
		return CHECKER_KICKED;
	}
	
	fields[to].push_back(*(--fields[from].end()));
	fields[from].pop_back();
	return CORRECT_MOVE;
*/
