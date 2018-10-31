#ifndef MOUSE_H
#define MOUSE_H

#include "actor.h"
#include "cheese.h"

class Maze;
class Mouse : public Actor {
private:
	//char icon[3];
	//int middle_row;
	//int middle_column;
	//int tail_row;
	//int tail_column;
	bool door_cheese_eaten;
	int cheese_eaten;
	int escape_cheese_eaten;
	void change_dir(Direction d);
public:
	Mouse(int row_, int column_);
	// Called by Maze::move_mice to move the mice.
	virtual bool move(int level, Direction d, bool is_non_player_mouse, char & old); //for single char avatars only
	//bool spit_cheese(Mouse * m); //FIX
	// Finds facing column and row respectively.
	int get_facing_c(); // return position mouse is facing
	int get_facing_r(); // return position mouse is facing
	virtual ~Mouse();
	// get and set the two private member variables
	// Get and set various cheese behaviors
	int get_door_cheese_eaten();
	void set_door_cheese_eaten(bool yes_or_no);
	int get_cheese_eaten();
	void set_cheese_eaten(int amount);
	int get_escape_cheese_eaten();
	void set_escape_cheese_eaten(int amount);
};


#endif