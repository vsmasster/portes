#include <bits/stdc++.h>
#include "board.hpp"
#include "constants.hpp"
using namespace std;

int main(){
	Board board;
	board.init();
	
	for(int i=0;i<BOARD_SIZE;i++){
		cout<<"Field "<<i+1<<": ";
		Field field = board.getField(i);
		if(field.empty()){cout<<"empty"<<endl;continue;}
		cout<<"color = "<<field.getColor()<<" ";
		cout<<"content = {";
		while(!field.empty()){
			cout<<field.back().num<<",";
			field.popBack();
		}
		cout<<"}"<<endl;
	}
	return 0;
}
