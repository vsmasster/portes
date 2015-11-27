#include "board.hpp"

void Field::pushBack(Checker checker){
	checkers.push_back(checker);
	color = checker.color;
}

void Field::popBack(){
	checkers.pop_back();
}

COLOR Field::getColor(){
	return color;
}

bool Field::empty(){
	return checkers.empty();
}

Checker Field::back(){
	return checkers.back();
}

int Field::size(){
	return checkers.size();
}

void Board::init(){
	fields[0].pushBack({0,BLACK});
	fields[0].pushBack({1,BLACK});
	fields[11].pushBack({2,BLACK});
	fields[11].pushBack({3,BLACK});
	fields[11].pushBack({4,BLACK});
	fields[11].pushBack({5,BLACK});
	fields[11].pushBack({6,BLACK});
	fields[16].pushBack({7,BLACK});
	fields[16].pushBack({8,BLACK});
	fields[16].pushBack({9,BLACK});
	fields[18].pushBack({10,BLACK});
	fields[18].pushBack({11,BLACK});
	fields[18].pushBack({12,BLACK});
	fields[18].pushBack({13,BLACK});
	fields[18].pushBack({14,BLACK});
	fields[5].pushBack({0,WHITE});
	fields[5].pushBack({1,WHITE});
	fields[5].pushBack({2,WHITE});
	fields[5].pushBack({3,WHITE});
	fields[5].pushBack({4,WHITE});
	fields[7].pushBack({5,WHITE});
	fields[7].pushBack({6,WHITE});
	fields[7].pushBack({7,WHITE});
	fields[12].pushBack({8,WHITE});
	fields[12].pushBack({9,WHITE});
	fields[12].pushBack({10,WHITE});
	fields[12].pushBack({11,WHITE});
	fields[12].pushBack({12,WHITE});
	fields[23].pushBack({13,WHITE});
	fields[23].pushBack({14,WHITE});
}

void Board::move(int from, int to, COLOR color){
	Checker checker;
	if(from == BAR_FIELD){
		checker = bar[color].back();
		bar[color].pop_back();
	}else{
		checker = fields[from].back();
		fields[from].popBack();
	}
		
	if(to == OFF_FIELD)
		ch_off[color]++;
	else{
		if(fields[to].size() == 1 && fields[to].color != color){ //kicking checker
			bar[!color].push_back(fields[to].back());
			fields[to].popBack();
		}
		fields[to].pushBack(checker);
	}
}

bool Board::checkerInBar(COLOR color){
	return !bar[color].empty();
}

COLOR Board::getFieldColor(int field_id){
	return fields[field_id].color;
}

Field Board::getField(int field_id){
	return fields[field_id];
}

void Board::print(){
	cout<<"BOARD:"<<endl;
	int mx_up = 0;
	for(int i=12;i<24;i++)mx_up = max(mx_up,fields[i].size());
	for(int i=0;i<mx_up;i++){
		for(int j=12;j<24;j++){
			if(j == 18 && bar[0].size() > i)cout<<"|W|";
			else if(j == 18)cout<<"| |";
			if(fields[j].size() > i)
				cout<< (fields[j].getColor() == BLACK ? "B" : "W");
			else cout<< (i == 0 ? "." : " ");
		}
		cout<<endl;
	}
	
	for(int i=0;i<6;i++)cout<<" ";
	cout<<"| |";
	for(int i=0;i<6;i++)cout<<" ";
	cout<<endl;
	int mx_down = 0;
	for(int i=11;i>=0;i--)mx_down = max(mx_down,fields[i].size());
	for(int i=mx_down-1;i>=0;i--){
		for(int j=11;j>=0;j--){
			if(j == 5 && bar[1].size() > i)cout<<"|B|";
			else if(j == 5)cout<<"| |";
			if(fields[j].size() > i)
				cout<< (fields[j].getColor() == BLACK ? "B" : "W");
			else cout<< (i == 0 ? "." : " ");
		}
		cout<<endl;
	}
}


