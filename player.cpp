#include "player.hpp"

Player::Player(Judge* _judge,bool _ai,COLOR color){
	judge = _judge;
	ai = _ai;
	if(ai)ai_handler = new AI(judge,color);
	this->color = color;
	board.init();
}

string Player::getName(){
	if(ai)return ai_handler->getName();
	cout<<"What is your name?"<<endl;
	cin>>name;
	return name;
}
/*
inline bool try_move(Board board, vector< pair<int, int> > moves, COLOR color){
	for (auto& move : moves){
		if ((move.first == BAR_FIELD && board.getBarSize(color) == 0) || (move.first != BAR_FIELD && board.getBarSize(color) != 0))
			return false;

		if (move.first != BAR_FIELD && (board.getField(move.first).size() == 0 || board.getField(move.first).getColor() != color))
			return false;

		if (move.second < OFF_FIELD && (board.getField(move.second).size() > 1 && board.getField(move.second).getColor() != color))
			return false;

		if (move.second >= OFF_FIELD){
			if (color == BLACK){
				for (int i = 0; i<18; i++)
					if (board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
						return false;

				if (move.second > OFF_FIELD){
					for (int i = 18; i<move.first; i++)
						if (board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
							return false;
				}
			}
			else{
				for (int i = 6; i<24; i++)
					if (board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
						return false;

				if (move.second > OFF_FIELD){
					for (int i = 5; i>move.first; i--)
						if (board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
							return false;
				}
			}
		}

		board.move(move.first, move.second, color);
	}

	return true;
}

vector< vector< pair<int, int> > > generate_moves(Board board, pair<int, int> dice, COLOR color){
	vector< vector< pair<int, int> > > result;
	if (dice.first != dice.second){
		//first move with first dice
		if (color == BLACK){
			for (int i = BAR_FIELD; i < OFF_FIELD - dice.first + 1; i++){
				for (int j = BAR_FIELD; j < OFF_FIELD - dice.second + 1; j++){
					vector< pair<int, int> > temp;
					temp.push_back(make_pair(i, i + dice.first));
					temp.push_back(make_pair(j, j + dice.second));
					if (try_move(board, temp, BLACK))
						result.push_back(temp);
				}
			}

		}
		else{
			for (int i = OFF_FIELD; i>BAR_FIELD + dice.first - 1; i--)
				for (int j = OFF_FIELD; j> BAR_FIELD + dice.second - 1; j--){
				vector< pair<int, int> > temp;
				int first, second;
				if (i == OFF_FIELD)first = BAR_FIELD;
				else if (i == BAR_FIELD)first = OFF_FIELD;
				else first = i;
				if (j == OFF_FIELD)second = BAR_FIELD;
				else if (j == BAR_FIELD)second = OFF_FIELD;
				else second = j;
				temp.push_back(make_pair(first, i - dice.first));
				temp.push_back(make_pair(second, j - dice.second));
				if (try_move(board, temp, WHITE)){
					result.push_back(temp);
				}
				}
		}

		//first move with second dice
		if (color == BLACK){
			for (int i = BAR_FIELD; i<OFF_FIELD - dice.second + 1; i++)
				for (int j = BAR_FIELD; j<OFF_FIELD - dice.first + 1; j++){
				vector< pair<int, int> > temp;
				temp.push_back(make_pair(i, i + dice.second));
				temp.push_back(make_pair(j, j + dice.first));
				if (try_move(board, temp, BLACK))
					result.push_back(temp);

				}
		}
		else{
			for (int i = OFF_FIELD; i>BAR_FIELD + dice.second - 1; i--)
				for (int j = OFF_FIELD; j> BAR_FIELD + dice.first - 1; j--){
				vector< pair<int, int> > temp;
				int first, second;
				if (i == OFF_FIELD)first = BAR_FIELD;
				else if (i == BAR_FIELD)first = OFF_FIELD;
				else first = i;
				if (j == OFF_FIELD)second = BAR_FIELD;
				else if (j == BAR_FIELD)second = OFF_FIELD;
				else second = j;
				temp.push_back(make_pair(first, i - dice.second));
				temp.push_back(make_pair(second, j - dice.first));
				if (try_move(board, temp, WHITE))
					result.push_back(temp);
				}
		}
	}
	else{
		if (color == BLACK){
			for (int i = BAR_FIELD; i<OFF_FIELD - dice.first + 1; i++)
				for (int j = i; j<OFF_FIELD - dice.first + 1; j++)
					for (int k = j; k<OFF_FIELD - dice.first + 1; k++)
						for (int l = k; l<OFF_FIELD - dice.first + 1; l++){
				vector< pair<int, int> > temp;
				temp.push_back(make_pair(i, i + dice.first));
				temp.push_back(make_pair(j, j + dice.first));
				temp.push_back(make_pair(k, k + dice.first));
				temp.push_back(make_pair(l, l + dice.first));
				if (try_move(board, temp, BLACK)){
					result.push_back(temp);
				}

						}
		}
		else{
			for (int i = OFF_FIELD; i>BAR_FIELD + dice.first - 1; i--)
				for (int j = i; j>BAR_FIELD + dice.first - 1; j--)
					for (int k = j; k>BAR_FIELD + dice.first - 1; k--)
						for (int l = k; l>BAR_FIELD + dice.first - 1; l--){
				vector< pair<int, int> > temp;
				temp.push_back(make_pair(i, i + dice.first));
				temp.push_back(make_pair(j, j + dice.first));
				temp.push_back(make_pair(k, k + dice.first));
				temp.push_back(make_pair(l, l + dice.first));
				if (try_move(board, temp, WHITE))
					result.push_back(temp);

						}
		}

	}

	if (dice.first != dice.second){
		for (int i = 0; i < result.size(); i++){
			for (int j = i+1; j < result.size(); j++){
				if (result[i][1] == result[j][0] && result[i][0] == result[j][1] && board.getFieldColor(result[i][0].second) != !color){
					swap(result[j], result[result.size() - 1]);
					result.pop_back();
					j--;
				}
			}
		}
	}

	return result;
}*/

void Player::turn(Board board){
	if(ai)return ai_handler->turn(board);
	auto dice = judge->rollDice();
	cout << "Dice: " << dice.first << " " << dice.second << endl;
	board.print();
	/*cout << "Possible moves: " << endl;
	auto pmoves = generate_moves(board, dice, color);
	for (auto p : pmoves){
		for (int i = 0; i < p.size(); i++)
			cout << p[i].first << "-->" << p[i].second << ", ";

			cout << endl;
	}*/
	vector < pair<int, int> > moves;
	for (int i = 0; i < (dice.first == dice.second ? 4 : 2); i++){
		int a, b; cin >> a >> b;
		moves.push_back(make_pair(a, b));
	}
	
	for (auto move : moves)
		judge->move(move.first, move.second, WHITE);
}
