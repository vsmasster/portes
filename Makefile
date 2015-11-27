CC=g++
CXXFLAGS=-std=c++14
OBJS=board.cpp ai.cpp judge.cpp player.cpp main.cpp
	
portes: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o portes
