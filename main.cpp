#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "checker.hpp"
#include "judge.hpp"
#include "player.hpp"
using namespace std;

int main(){
	srand(time(0));
	Judge *judge = new Judge;
	Player *pl1_handler = new Player(judge,true,BLACK);
	Player *pl2_handler = new Player(judge,false,WHITE);
	judge->registerPlayers(pl1_handler,pl2_handler);
	cout<< "Please tell us what are your names?" <<endl;
	string name1 = pl1_handler->getName();
	string name2 = pl2_handler->getName();
	cout<< "So, "<< name1 << " plays against " << name2 << endl;
	cout<< "Good luck and don't cheat!" <<endl;
	while(judge->isAlive())judge->log();
	
	return 0;
}
