#ifndef MAZE_H
#define MAZE_H

#include "mouse.h"
#include "cheese.h"
#include "globals.h"
#include "bug.h"
#include <string>

using namespace std;

//sharp include user interface or whatever

class Maze {
private:
	//will change later
	char map[MAX_LEVEL][MAZE_HEIGHT][MAZE_WIDTH];  //[level][r][c]
	Cheese *cheese_ar_l1[MAX_LEVEL][MAX_CHEESE_PER_LEVEL];  //[level][num]
	//Cheese * sp_ar[5][20]; //[level][num] not implemented
	//Bug *bug_ar[1][2]; //[level][num] not implemented
	Mouse * mouse;
	Mouse * mirror_mouse;
	Mouse * player_mouse;
	Cheese *cheese;
	string status[MAX_LEVEL][10];
	char nonplayer_mouse_tile;
	bool is_escaped;

	void set_char(int level, int row, int col, char someChar); //
	void test_level();
	void load_level(int level);
	void eat_cheese(int level, int row, int col);
	void eat_door(int &level);
	Cheese * get_cheese_at(int level, int row, int col) const;
	void flip_to_mirror();
	void set_status(int level);
	Cheese * searchCheese(int level, int row, int col) const;

public:
	Maze(bool is_test); // construct 2 mice, point player_mouse at mouse
	~Maze();
	char get_char(int level, int row, int col);
	void move_mice(int level, Direction dir);
	void try_actions(int &level);
	string get_status(int level, int line);
	void reset(int level);
	void place_actors();
	//void spit(int level, int r, int c);
	//bool is_edible(int level);
	//bool escaped();
	
};
#endif