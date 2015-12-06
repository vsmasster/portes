#include "judge.hpp"

Judge::Judge(){
	board.init();
}

pair<int,int> Judge::rollDice(){
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;
	dice.first = a;
	dice.second = b;
	return make_pair(a,b);
}

bool Judge::isAlive(){
	pl1_handler->turn(board);
	pl2_handler->turn(board);
	return !board.isTerminalState();
}

void Judge::registerPlayers(Player* pl1,Player* pl2){
	pl1_handler = pl1;
	pl2_handler = pl2;
}

void Judge::log(){
	board.print();
}

bool Judge::correct_move(pair<int, int> move, COLOR color){
	if ((move.first == BAR_FIELD && board.getBarSize(color) == 0) || (move.first != BAR_FIELD && board.getBarSize(color) != 0))
		return false;

	if (move.first != BAR_FIELD && (board.getField(move.first).size() == 0 || board.getField(move.first).getColor() != color))
		return false;

	if (move.second < OFF_FIELD && (board.getField(move.second).size() > 1 && board.getField(move.second).getColor() != color))
		return false;

	if (move.second >= OFF_FIELD){
		if (color == BLACK){
			for (int i = 0; i < 18; i++)
				if (board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
					return false;
			if (move.second > OFF_FIELD){
				for (int i = 18; i < move.first; i++)
					if (board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
						return false;
			}
		}
		else{
			for (int i = 6; i < 24; i++){
				if (board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
					return false;
				if (move.second > OFF_FIELD){
					for (int i = 5; i > move.first; i--)
						if (board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
							return false;
				}
			}
		}
	}
	return true;
}

bool Judge::move(int from,int to,COLOR color){
	if (correct_move(make_pair(from, to), color)){
		cout << "SUCCESS!" << endl;
		board.move(from, to, color);
		return true;
	}

	cout << "WRONG MOVE!" << endl;
	return false;
}

vector< pair<int,int> > Judge::getLastMoves(){
	return last_moves;
}


