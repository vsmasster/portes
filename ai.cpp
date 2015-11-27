#include "ai.hpp"

AI::AI(Judge* j,COLOR c){
	judge = j;
	color = c;
	board.init();
}

string AI::getName(){
	return "WorldDestroyer";
}
/*
//gets vector of moves sequention and chekcs if are correct on given board
bool try_move(Board board,vector< pair<int,int> > moves){ 
	for(auto move: moves){
		if((move.first == BAR_FIELD && board.bar[BLACK].size() == 0) || (move.first != BAR_FIELD && board.bar[BLACK].size() != 0))
			return false;
			
		if(move.first != BAR_FIELD && (board.getField(move.first).size() == 0 || board.getField(move.first).getColor() == WHITE))
			return false;
			
		if(move.second < OFF_FIELD && (board.getField(move.second).size() > 1 && board.getField(move.second).getColor() == WHITE))
			return false;
			
		if(move.second >= OFF_FIELD){
			for(int i=0;i<18;i++)
				if(board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
					return false;
					
			if(move.second > OFF_FIELD){
				for(int i=18;i<move.first;i++)
					if(board.getField(i).size() != 0 && board.getField(i).getColor() == BLACK)
						return false;
			}
		}
		
		board.move(move.first,move.second,BLACK);
	}
	
	return true;
}

vector< vector< pair<int,int> > > generate_moves(Board board,pair<int,int> dice){
	vector< vector< pair<int,int> > > result;
	if(dice.first != dice.second){
		//first move with first dice
		for(int i=BAR_FIELD;i<OFF_FIELD;i++)
			for(int j=BAR_FIELD;j<OFF_FIELD;j++){
				vector< pair<int,int> > temp;
				temp.push_back(make_pair(i,i+dice.first));
				temp.push_back(make_pair(j,j+dice.second));
				if(try_move(board,temp))
					result.push_back(temp);
			}
					
		//first move with second dice
		for(int i=BAR_FIELD;i<OFF_FIELD;i++)
			for(int j=BAR_FIELD;j<OFF_FIELD;j++){
				vector< pair<int,int> > temp;
				temp.push_back(make_pair(i,i+dice.second));
				temp.push_back(make_pair(j,j+dice.first));
				if(try_move(board,temp))
					result.push_back(temp);
					
			}
	}else{
		for(int i=BAR_FIELD;i<OFF_FIELD;i++)
			for(int j=i;j<OFF_FIELD;j++)
				for(int k=j;k<OFF_FIELD;k++)
					for(int l=k;l<OFF_FIELD;l++){
						vector< pair<int,int> > temp;
						temp.push_back(make_pair(i,i+dice.first));
						temp.push_back(make_pair(j,j+dice.first));
						temp.push_back(make_pair(k,k+dice.first));
						temp.push_back(make_pair(l,l+dice.first));
						if(try_move(board,temp))
							result.push_back(temp);
							
					}
				
	}
	
	return result;
}
*/
void AI::turn(){
	/*
	board.print();
	pair<int,int> dice = judge->rollDice();
	vector< vector< pair<int,int> > > moves = generate_moves(board,dice);
	cout<< "Dice: "<<dice.first<<" "<<dice.second<<endl;
	for(auto move: moves){
		for(auto m: move)
			cout<< m.first <<" --> "<<m.second<<", ";
		
		cout<<endl;
	}
	
	if(moves.empty())return;
	auto move = rand()%moves.size();
	* */
}
