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

void Board::kickChecker(int field_id,COLOR color){
	bar[color].push_back(fields[field_id].back());
	fields[field_id].popBack();
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
	else fields[to].pushBack(checker);
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


