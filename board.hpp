#ifndef board_h
#define board_h
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "constants.hpp"
using namespace std;

enum COLOR{
	NO_COLOR = -1,
	WHITE = 0,
	BLACK = 1,
};

class Board;

class Field{
friend class Board;

private:
	int checkers;
	COLOR color;
	
public:
	Field() :checkers(0){}
	friend bool operator==(Field& f1, Field& f2);
	void add(COLOR c,int num);
	void remove();
	int size();
	bool empty();
	COLOR getColor();
};

class Board{
private:
	Field fields[24];
	int bar[2];
	int ch_off[2];
	
public:
	friend bool operator==(Board& b1,Board& b2);
	void init();
	void move(int from,int to,COLOR color);
	void print();
	
	COLOR getFieldColor(int field_id);
	Field getField(int field_id);
	
	bool checkerInBar(COLOR color);
	bool isFieldEmpty(int field_id);

	int getBarSize(COLOR color);
	int getNumOff(COLOR color);

	bool isTerminalState();
};

#endif
