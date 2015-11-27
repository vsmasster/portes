#include "player.hpp"

Player::Player(Judge* _judge,bool _ai,COLOR color){
	judge = _judge;
	ai = _ai;
	if(ai)ai_handler = new AI(judge,color);
	board.init();
}

string Player::getName(){
	if(ai)return ai_handler->getName();
	cout<<"What is your name?"<<endl;
	cin>>name;
	return name;
}

void Player::turn(){
	if(ai)return ai_handler->turn();
	auto dice = judge->rollDice();
	cout<< "Dice: "<<dice.first<<" "<<dice.second;
	board.print();
	int from,to;
	cin>>from>>to;
	while(!judge->move(from,to))
		cin>>from>>to;
		
	board.move(from,to,BLACK);
}
