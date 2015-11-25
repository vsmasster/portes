#include "player.hpp"

Player::Player(Judge* _judge,bool _ai){
	judge = _judge;
	ai = ai;
}

string Player::getName(){
	//if(ai)return ai_handler.getName();
	cout<<"What is your name?"<<endl;
	cin>>name;
	return name;
}

void Player::turn(){
	judge->rollDice();
}
