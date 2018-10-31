#include "actor.h"
#include "maze.h"


Actor::Actor(int row_, int column_, int health_, char icon_)
	: row(row_), column(column_), health(health_), icon(icon_), maze(nullptr) {}

void Actor::set_maze(Maze * new_maze) {
	maze = new_maze;
}
void Actor::set_row(int r) {
	row = r;
}
void Actor::set_column(int c) {
	column = c;
}
void Actor::set_direction(Direction d) {
	dir = d;
}
void Actor::set_position(int r, int c) {
	set_row(r);
	set_column(c);
}
void Actor::decrease_health(int h) {
	health -= h;
}
void Actor::set_icon(char c) {
	icon = c;
}
void Actor::increase_health(int h) {
	health += h;
}
Actor::~Actor() {
	maze = nullptr;
}