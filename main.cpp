#include <bits/stdc++.h>
#include "board.hpp"
#include "judge.hpp"
#include "player.hpp"
#include "constants.hpp"
using namespace std;

int main(){
	Judge* judge = new Judge();
	Player pl1_handler(judge,false),pl2_handler(judge,false);
	while(judge->isAlive()){
		pl1_handler.turn();
		pl2_handler.turn();
		judge->log();
	}
	
	return 0;
}
