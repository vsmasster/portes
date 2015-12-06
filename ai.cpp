#include "ai.hpp"

AI::AI(Judge* j,COLOR c){
	judge = j;
	color = c;
}

string AI::getName(){
	return "WorldDestroyer";
}

//gets vector of moves sequention and chekcs if are correct on given board
inline bool try_move(Board board,vector< pair<int,int> > moves,COLOR color){
	for (auto& move: moves){
		if ((move.first == BAR_FIELD && board.getBarSize(color) == 0) || (move.first != BAR_FIELD && board.getBarSize(color) != 0))
			return false;
			
		if(move.first != BAR_FIELD && (board.getField(move.first).size() == 0 || board.getField(move.first).getColor() != color))
			return false;
			
		if(move.second < OFF_FIELD && (board.getField(move.second).size() > 1 && board.getField(move.second).getColor() != color))
			return false;
			
		if(move.second >= OFF_FIELD){
			if(color == BLACK){
				for(int i=0;i<18;i++)
					if(board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
						return false;
						
				if(move.second > OFF_FIELD){
					for(int i=18;i<move.first;i++)
						if(board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
							return false;
				}
			}else{
				for(int i=6;i<24;i++)
					if(board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
						return false;
						
				if(move.second > OFF_FIELD){
					for(int i=5;i>move.first;i--)
						if(board.getField(i).size() != 0 && board.getField(i).getColor() == WHITE)
							return false;
				}
			}
		}
		
		board.move(move.first,move.second,color);
	}

	return true;
}

vector< vector< pair<int,int> > > generate_moves(Board board,pair<int,int> dice,COLOR color){
	vector< vector< pair<int,int> > > result;
	if(dice.first != dice.second){
		//first move with first dice
		if (color == BLACK){
			for (int i = BAR_FIELD; i < OFF_FIELD-dice.first+1; i++){
				for (int j = BAR_FIELD; j < OFF_FIELD-dice.second+1; j++){
					vector< pair<int, int> > temp;
					temp.push_back(make_pair(i, i + dice.first));
					temp.push_back(make_pair(j, j + dice.second));
					if (try_move(board, temp, BLACK))
						result.push_back(temp);
				}
			}

		}else{
			for(int i=OFF_FIELD;i>BAR_FIELD+dice.first-1;i--)
				for(int j=OFF_FIELD;j> BAR_FIELD+dice.second-1;j--){
					vector< pair<int,int> > temp;
					int first,second;
					if(i == OFF_FIELD)first = BAR_FIELD;
					else if(i == BAR_FIELD)first = OFF_FIELD;
					else first = i;
					if(j == OFF_FIELD)second = BAR_FIELD;
					else if(j == BAR_FIELD)second = OFF_FIELD;
					else second = j;
					temp.push_back(make_pair(first,i-dice.first));
					temp.push_back(make_pair(second,j-dice.second));
					if (try_move(board, temp, WHITE)){
						result.push_back(temp);
					}
				}
		}
					
		//first move with second dice
		if(color == BLACK){
			for(int i=BAR_FIELD;i<OFF_FIELD-dice.second+1;i++)
				for(int j=BAR_FIELD;j<OFF_FIELD-dice.first+1;j++){
					vector< pair<int,int> > temp;
					temp.push_back(make_pair(i,i+dice.second));
					temp.push_back(make_pair(j,j+dice.first));
					if(try_move(board,temp,BLACK))
						result.push_back(temp);
						
				}
		}else{
			for(int i=OFF_FIELD;i>BAR_FIELD+dice.second-1;i--)
				for(int j=OFF_FIELD;j> BAR_FIELD+dice.first-1;j--){
					vector< pair<int,int> > temp;
					int first,second;
					if(i == OFF_FIELD)first = BAR_FIELD;
					else if(i == BAR_FIELD)first = OFF_FIELD;
					else first = i;
					if(j == OFF_FIELD)second = BAR_FIELD;
					else if(j == BAR_FIELD)second = OFF_FIELD;
					else second = j;
					temp.push_back(make_pair(first,i-dice.second));
					temp.push_back(make_pair(second,j-dice.first));
					if(try_move(board,temp,WHITE))
						result.push_back(temp);
				}
		}
	}else{
		if(color == BLACK){
			for(int i=BAR_FIELD;i<OFF_FIELD-dice.first+1;i++)
				for (int j = i; j<OFF_FIELD - dice.first + 1; j++)
					for (int k = j; k<OFF_FIELD - dice.first + 1; k++)
						for (int l = k; l<OFF_FIELD - dice.first + 1; l++){
							vector< pair<int,int> > temp;
							temp.push_back(make_pair(i,i+dice.first));
							temp.push_back(make_pair(j,j+dice.first));
							temp.push_back(make_pair(k,k+dice.first));
							temp.push_back(make_pair(l,l+dice.first));
							if (try_move(board, temp, BLACK)){
								result.push_back(temp);
							}
								
						}
		}else{
			for (int i = OFF_FIELD; i>BAR_FIELD + dice.first - 1; i--)
				for (int j = i; j>BAR_FIELD + dice.first - 1; j--)
					for (int k = j; k>BAR_FIELD + dice.first - 1; k--)
						for (int l = k; l>BAR_FIELD + dice.first - 1; l--){
							vector< pair<int,int> > temp;
							temp.push_back(make_pair(i,i+dice.first));
							temp.push_back(make_pair(j,j+dice.first));
							temp.push_back(make_pair(k,k+dice.first));
							temp.push_back(make_pair(l,l+dice.first));
							if(try_move(board,temp,WHITE))
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
}
long long nodes;
double expect(Board board,pair<int,int> dice,int depth,int mv,double alpha,double beta){
	printf("%lld %d %d %d\n", ++nodes,dice.first,dice.second,depth);
	if (depth == 0 || board.isTerminalState())
		return 0.055*(double)(board.getBarSize(WHITE) - board.getBarSize(BLACK));
	
	if(mv == 2){ //random node
		double res = 0.0;
		for(int i=1;i<=6;i++)
			for(int j=i;j<=6;j++)
				res += 1.0/36.0 * expect(board,make_pair(i,j),depth,depth%2,alpha,beta);
		
		return res;
	}else if(mv == 0){//opponent move
		vector< vector< pair<int,int> > > moves = generate_moves(board,dice,WHITE);
		for(auto move: moves){
			Board temp = board;
			for(int i=0;i<move.size();i++)
				temp.move(move[i].first,move[i].second,WHITE);
				
			beta = min(beta,expect(temp,dice,depth-1,2,alpha,beta));
			if (alpha >= beta)
				break;
		}
		
		return beta;
	}else{//my move
		vector< vector< pair<int,int> > > moves = generate_moves(board,dice,BLACK);
		for(auto move: moves){
			Board temp = board;
			for(int i=0;i<move.size();i++)
				temp.move(move[i].first,move[i].second,BLACK);
				
			alpha = max(alpha,expect(temp,dice,depth-1,2,alpha,beta));
			if (alpha >= beta)
				break;
		}
		
		return alpha;
	}
}

void AI::turn(Board board){
	cout << "Now me gonna conquer the world!" << endl;
	pair<int,int> dice = judge->rollDice();
	vector< vector< pair<int,int> > > moves = generate_moves(board,dice,BLACK);
	cout<< "Dice: "<<dice.first<<" "<<dice.second<<endl;
	/*
	for(auto move: moves){
		for(auto m: move)
			cout<< m.first <<" --> "<<m.second<<", ";
		
		cout<<endl;
	}*/
	
	if(moves.empty())return;
	double alpha = -10000.0;
	int it = 0;
	
	for(int j=0;j<moves.size();j++){
		auto move = moves[j];
		Board temp = board;
		for(int i=0;i<move.size();i++)
			temp.move(move[i].first,move[i].second,BLACK);
			
		double res = expect(temp,dice,2,2,-100000.0,+100000.0);
		if(res > alpha){
			alpha = res;
			it = j;
		}
	}

	cout << nodes << endl;

	for(auto mv: moves[it])
		judge->move(mv.first,mv.second,BLACK);
}
