#include "board.hpp"

void Field::add(COLOR c, int num = 1){
	checkers += num;
	color = c;
}

void Field::remove(){
	checkers--;
	if (checkers == 0)color = NO_COLOR;
}

COLOR Field::getColor(){
	return color;
}

bool Field::empty(){
	return checkers == 0;
}

int Field::size(){
	return checkers;
}

bool operator==(Field& f1,Field& f2){
	if (f1.size() != f2.size())return false;
	if (f1.size() == 0 && f2.size() == 0)return true;
	return f1.color == f2.color;
}

void Board::init(){
	for (int i = 0; i < 24; i++)fields[i].add(NO_COLOR, 0);
	fields[0].add(BLACK,2);
	fields[11].add(BLACK,5);
	fields[16].add(BLACK,3);
	fields[18].add(BLACK,5);
	fields[5].add(WHITE,5);
	fields[7].add(WHITE,3);
	fields[12].add(WHITE,5);
	fields[23].add(WHITE,2);

	ch_off[0] = 0;
	ch_off[1] = 0;
	bar[0] = 0;
	bar[1] = 0;
}

bool operator==(Board& b1,Board& b2){
	for (int i = 0; i < 24; i++)
		if (!(b1.getField(i) == b2.getField(i)))return false;

	if (b1.bar[WHITE] != b2.bar[WHITE])return false;
	if (b1.bar[BLACK] != b2.bar[BLACK])return false;

	return true;
}

void Board::move(int from, int to, COLOR color){
	if(from == BAR_FIELD){
		bar[color]--;
	}else{
		fields[from].remove();
	}
		
	if(to == OFF_FIELD)
		ch_off[color]++;
	else{
		if(fields[to].size() == 1 && fields[to].color != color){ //kicking checker
			bar[!color]++;
			fields[to].remove();
		}
		fields[to].add(color);
	}
}

bool Board::checkerInBar(COLOR color){
	return bar[color];
}

COLOR Board::getFieldColor(int field_id){
	return fields[field_id].color;
}

Field Board::getField(int field_id){
	return fields[field_id];
}

void Board::print(){
	cout<<"BOARD:"<<endl;
	for (int i = 12; i <= 17; i++)
		cout << i % 10;
	cout << "   ";
	for (int i = 18; i < 24; i++)
		cout << i % 10;
	cout << endl;
	int mx_up = 0;
	for(int i=12;i<24;i++)mx_up = max(mx_up,fields[i].size());
	for(int i=0;i<mx_up;i++){
		for(int j=12;j<24;j++){
			if(j == 18 && bar[0] > i)cout<<"|W|";
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
			if(j == 5 && bar[1] > i)cout<<"|B|";
			else if(j == 5)cout<<"| |";
			if(fields[j].size() > i)
				cout<< (fields[j].getColor() == BLACK ? "B" : "W");
			else cout<< (i == 0 ? "." : " ");
		}
		cout<<endl;
	}

	for (int i = 11; i >= 6; i--)
		cout << i % 10;

	cout << "   ";
	for (int i = 5; i >= 0; i--)
		cout << i % 10;
	cout << endl;
}

int Board::getBarSize(COLOR color){
	return bar[color];
}

int Board::getNumOff(COLOR color){
	return ch_off[color];
}

bool Board::isTerminalState(){
	return ch_off[0] == 15 || ch_off[1] == 15;
}


