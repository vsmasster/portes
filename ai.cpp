#include "ai.hpp"

AI::AI(Judge* j,COLOR c){
	judge = j;
	color = c;
	board.init();
}

string AI::getName(){
	return "WorldDestroyer";
}

//gets vector of moves sequention and chekcs if are correct on given board
bool try_move(Board board,vector< pair<int,int> > moves,COLOR color){ 
	for(auto move: moves){
		if((move.first == BAR_FIELD && board.bar[color].size() == 0) || (move.first != BAR_FIELD && board.bar[color].size() != 0))
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
		
		board.move(move.first,move.second,BLACK);
	}
	
	return true;
}

vector< vector< pair<int,int> > > generate_moves(Board board,pair<int,int> dice,COLOR color){
	vector< vector< pair<int,int> > > result;
	if(dice.first != dice.second){
		//first move with first dice
		if(color == BLACK){	
			for(int i=BAR_FIELD;i<OFF_FIELD;i++)
				for(int j=BAR_FIELD;j<OFF_FIELD;j++){
					vector< pair<int,int> > temp;
					temp.push_back(make_pair(i,i+dice.first));
					temp.push_back(make_pair(j,j+dice.second));
					if(try_move(board,temp,BLACK))
						result.push_back(temp);
				}
		}else{
			for(int i=OFF_FIELD;i>BAR_FIELD;i--)
				for(int j=OFF_FIELD;j> BAR_FIELD;j--){
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
					if(try_move(board,temp,WHITE))
						result.push_back(temp);
				}
		}
					
		//first move with second dice
		if(color == BLACK){
			for(int i=BAR_FIELD;i<OFF_FIELD;i++)
				for(int j=BAR_FIELD;j<OFF_FIELD;j++){
					vector< pair<int,int> > temp;
					temp.push_back(make_pair(i,i+dice.second));
					temp.push_back(make_pair(j,j+dice.first));
					if(try_move(board,temp,BLACK))
						result.push_back(temp);
						
				}
		}else{
			for(int i=OFF_FIELD;i>BAR_FIELD;i--)
				for(int j=OFF_FIELD;j> BAR_FIELD;j--){
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
			for(int i=BAR_FIELD;i<OFF_FIELD;i++)
				for(int j=i;j<OFF_FIELD;j++)
					for(int k=j;k<OFF_FIELD;k++)
						for(int l=k;l<OFF_FIELD;l++){
							vector< pair<int,int> > temp;
							temp.push_back(make_pair(i,i+dice.first));
							temp.push_back(make_pair(j,j+dice.first));
							temp.push_back(make_pair(k,k+dice.first));
							temp.push_back(make_pair(l,l+dice.first));
							if(try_move(board,temp,BLACK))
								result.push_back(temp);
								
						}
		}else{
			for(int i=OFF_FIELD;i>BAR_FIELD;i--)
				for(int j=i;j>BAR_FIELD;j--)
					for(int k=j;k>BAR_FIELD;k--)
						for(int l=k;k>BAR_FIELD;k--){
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
	
	return result;
}

bool terminal_state(Board board){
	return board.ch_off[BLACK] == 15;
}

double expectiminimax(Board board,pair<int,int> dice,int depth,int mv){
	//cout<<"DUPA"<<" "<<depth<<endl;
	if(depth == 0 || terminal_state(board))
		return 0.055*(double)(board.bar[WHITE].size() - board.bar[BLACK].size()) + 1.0;
	
	if(mv == 2){ //random node
		double alpha = 0.0;
		for(int i=1;i<=6;i++)
			for(int j=1;j<=6;j++)
				alpha += 1.0/36.0 * expectiminimax(board,make_pair(i,j),depth,depth%2);
		
		return alpha;
	}else if(mv == 0){//opponent move
		double alpha = 1000000.0;
		vector< vector< pair<int,int> > > moves = generate_moves(board,dice,WHITE);
		for(auto move: moves){
			Board temp = board;
			for(int i=0;i<move.size();i++)
				temp.move(move[i].first,move[i].second,WHITE);
				
			alpha = min(alpha,expectiminimax(temp,dice,depth-1,2));
		}
		
		return alpha;
	}else{//my move
		double alpha = -1000000.0;
		vector< vector< pair<int,int> > > moves = generate_moves(board,dice,BLACK);
		for(auto move: moves){
			Board temp = board;
			for(int i=0;i<move.size();i++)
				temp.move(move[i].first,move[i].second,BLACK);
				
			alpha = max(alpha,expectiminimax(temp,dice,depth-1,2));
		}
		
		return alpha;
	}
}

void AI::turn(){
	board.print();
	pair<int,int> dice = judge->rollDice();
	vector< vector< pair<int,int> > > moves = generate_moves(board,dice,BLACK);
	cout<< "Dice: "<<dice.first<<" "<<dice.second<<endl;
	for(auto move: moves){
		for(auto m: move)
			cout<< m.first <<" --> "<<m.second<<", ";
		
		cout<<endl;
	}
	
	if(moves.empty())return;
	double alpha = -10000.0;
	int it = 0;
	for(int j=0;j<moves.size();j++){
		auto move = moves[j];
		Board temp = board;
		for(int i=0;i<move.size();i++)
			temp.move(move[i].first,move[i].second,BLACK);
			
		double res = expectiminimax(temp,dice,4,2);
		if(res > alpha){
			alpha = res;
			it = j;
		}
	}
	cout<<"DUPA"<<endl;
	for(auto mv: moves[it]){
		judge->move(mv.first,mv.second,BLACK);
		board.move(mv.first,mv.second,BLACK);
	}
}
