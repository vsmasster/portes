#ifndef board_h
#define board_h
#include <bits/stdc++.h>
#include "checker.hpp"
#include "constants.hpp"
using namespace std;

class Board;

class Field{
friend class Board;

private:
	vector<Checker> checkers;
	COLOR color;
	
public:
	void pushBack(Checker checker);
	void popBack();
	bool empty();
	COLOR getColor();
	Checker back();
};

class Board{
private:
	Field fields[24];
	vector<Checker> bar[2];
	int ch_off[2];
	
public:
	void init();
	void move(int from,int to,COLOR color);
	void kickChecker(int field_id,COLOR color);
	
	COLOR getFieldColor(int field_id);
	Field getField(int field_id);
	
	bool checkerInBar(COLOR color);
	bool isFieldEmpty(int field_id);
	
};

#endif
