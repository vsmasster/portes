#ifndef board_h
#define board_h
#include <bits/stdc++.h>
#include "constants.hpp"
#include "checker.hpp"
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
	int size();
	bool empty();
	COLOR getColor();
	Checker back();
};

class Board{
private:
	Field fields[24];
	
public:
	void init();
	vector<Checker> bar[2];
	int ch_off[2];
	void move(int from,int to,COLOR color);
	void print();
	
	COLOR getFieldColor(int field_id);
	Field getField(int field_id);
	
	bool checkerInBar(COLOR color);
	bool isFieldEmpty(int field_id);
};

#endif
