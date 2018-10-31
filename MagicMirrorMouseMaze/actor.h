#ifndef ACTOR_H
#define ACTOR_H
#include "UserInterface.h"
#include "globals.h"
#include <iostream>

enum Direction { UP, DOWN, LEFT, RIGHT };

class Cheese;
class Maze;
class Actor {
private:
	int row;
	int column;
	int health;
	char icon;
	Maze * maze;
	Direction dir;
	void set_row(int r);
	void set_column(int c);
public:
	Actor(int row_, int column_, int health_, char icon_);

	//Places actor at certain row and column in the maze
	void set_position(int r, int c);

	//Points actors at the maze
	void set_maze(Maze * new_maze);

	//Change icon used in display
	void set_icon(char c);

	//Change direction actor is facing
	void set_direction(Direction d);

	//Decrease health by h points
	void decrease_health(int h);

	//Increase health by h points
	void increase_health(int h);

	//virtual void change_dir(Direction d) = 0;

	virtual bool move(int level, Direction d, bool is_non_player_mouse, char & old) = 0;

	//Returns actor's icon  character
	char get_icon() const { return icon; }

	//Returns actor's row
	int get_row() const { return row; }

	//Returns actor's column
	int get_column() const { return column; }

	//Returns actor's health
	int get_health() const { return health; }

	//Used by derived Mouse class to access maze pointer
	Maze * get_maze() { return maze; }

	//Used by derived Mouse class to access direction
	Direction get_direction() { return dir; }

	virtual ~Actor();
};


#endif