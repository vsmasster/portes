#include <bits/stdc++.h>
#include "checker.hpp"
#include "judge.hpp"
#include "player.hpp"
using namespace std;

int main(){
	Judge *judge = new Judge;
	Player *pl1_handler = new Player(judge,false,BLACK);
	Player *pl2_handler = new Player(judge,true,WHITE);
	judge->registerPlayers(pl1_handler,pl2_handler);
	cout<< "Please tell us what are your names?" <<endl;
	string name1 = pl1_handler->getName();
	string name2 = pl2_handler->getName();
	cout<< "So, "<< name1 << " plays against " << name2 << endl;
	cout<< "Good luck and don't cheat!" <<endl;
	while(judge->isAlive());
	
	return 0;
}
