#include "mouse.h"
#include "maze.h"

Mouse::Mouse(int row_, int column_)
	: Actor(row_, column_, MOUSE_HEALTH, '^'), door_cheese_eaten(0), cheese_eaten(0) {}

void Mouse::change_dir(Direction d) {
	set_direction(d);
	switch (d) {
	case UP:
		set_icon('^');
		break;
	case DOWN:
		set_icon('v');
		break;
	case LEFT:
		set_icon('<');
		break;
	case RIGHT:
		set_icon('>');
		break;
	}
}
//bool Mouse::spit_cheese(Mouse * mouse) { // FIX
//	Maze * m = get_maze();
//	if (mouse->cheese_eaten > 0) { // FIX
//		//Direction d = get_direction();
//		//int r_diff{};
//		//int c_diff{};
//		//// get rear of mouse
//		//switch (d) {
//		//case UP:
//		//	r_diff++; 
//		//	break;
//		//case DOWN:
//		//	r_diff--;
//		//	break;
//		//case LEFT:
//		//	//c_diff++;
//		//	break;
//		//case RIGHT:
//		//	c_diff--; 
//		//	break;
//		//}
//		if (get_maze()->get_char(0, get_facing_r(), get_facing_c()) == ' ') { //FIX LEVEL
//			get_maze()->spit(0, get_facing_r(), get_facing_c());
//			mouse->cheese_eaten--; // FIX
//			return true;
//		}
//	}
//	return false;
//}
int Mouse::get_facing_c() {
	Direction d = get_direction();
	switch (d) {
	case UP:case DOWN:
		return get_column();
	case LEFT:
		return get_column() - 1;
	case RIGHT:
		return get_column() + 1;
	default:
		return -1; // shouldl never return -1
	}
}
int Mouse::get_facing_r() {
	Direction d = get_direction();
	switch (d) {
	case UP:
		return get_row() - 1;
	case DOWN:
		return get_row() + 1;
	case LEFT: case RIGHT:
		return get_row();
	default:
		return -1; // shouldl never return -1
	}
}
Mouse::~Mouse() {}

int Mouse::get_door_cheese_eaten() {
	return door_cheese_eaten;
}
int Mouse::get_cheese_eaten() {
	return cheese_eaten;
}
int Mouse::get_escape_cheese_eaten() {
	return escape_cheese_eaten;
}
void Mouse::set_escape_cheese_eaten(int amount) {
	escape_cheese_eaten = amount;
}
void Mouse::set_door_cheese_eaten(bool yes_or_no) {
	door_cheese_eaten = yes_or_no;
}
void Mouse::set_cheese_eaten(int amount) {
	cheese_eaten = amount;
}

bool Mouse::move(int level, Direction d, bool is_nonplayer_mouse, char & old) {
	if (d != get_direction()) {
		change_dir(d);
	}
	else {
		int r_diff{};
		int c_diff{};
		switch (d) {
		case UP:
			r_diff--;  // lower row is higher up on screen
			break;
		case DOWN:
			r_diff++;
			break;
		case LEFT:
			c_diff--;
			break;
		case RIGHT:
			c_diff++;
			break;
		}
		if ((!is_nonplayer_mouse && get_maze()->get_char(level, get_row() + r_diff, c_diff + get_column()) == ' ')) {
			set_position(get_row() + r_diff, c_diff + get_column());
		}
		else if (is_nonplayer_mouse) {
			old = get_maze()->get_char(level, get_row() + r_diff, c_diff + get_column());
			set_position(get_row() + r_diff, c_diff + get_column());
		}
		else {
			return false;
		}
	}
	return true;
}