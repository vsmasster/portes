#include "judge.hpp"

Judge::Judge(){
	board.init();
}

pair<int,int> Judge::rollDice(){
	int a = random() % 6 + 1;
	int b = random() % 6 + 1;
	dice.first = a;
	dice.second = b;
	return make_pair(a,b);
}

bool Judge::ifEnd(){
	return board.ch_off[BLACK] == 15 || board.ch_off[WHITE] == 15;
}

bool Judge::isAlive(){
	pl1_handler->turn();
	return ifEnd();
}

void Judge::registerPlayers(Player* pl1,Player* pl2){
	pl1_handler = pl1;
	pl2_handler = pl2;
}

void Judge::log(){
	board.print();
}

bool Judge::move(int from,int to,COLOR color){
	board.move(from,to,color);
	return true;
}

vector< pair<int,int> > Judge::getLastMoves(){
	return last_moves;
}
