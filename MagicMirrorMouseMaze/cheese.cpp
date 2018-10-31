#include <cstdlib>
#include <random>

#include "actor.h"
#include "cheese.h"
#include "globals.h"
#include "mouse.h"

using namespace std;



// Cheese implementation.

Cheese::Cheese(int row_, int col_, char icon_, int remaining_, bool eat_now_) : row(row_), col(col_), icon(icon_), remaining(remaining_), eat_now(eat_now_) {}

Cheese::~Cheese() {}

char Cheese::get_icon() const {
	return icon;
}

int Cheese::get_remaining() const {
	return remaining;
}

int Cheese::get_row() const {
	return row;
}

int Cheese::get_col() const {
	return col;
}

void Cheese::set_row(int r) {
	row = r;
}

void Cheese::set_col(int c) {
	col = c;
}

void Cheese::decrease_remaining(int amount) {
	remaining -= amount;
}

// PureCheese implementation.

// LAST PARAM (BOOL) SHOULD BE SET TO TRUE OR FALSE???
PureCheese::PureCheese(int row_, int col_, char icon_) : Cheese(row_, col_, icon_, 10, false) {
	set_row(row_);
	set_col(col_);
}

PureCheese::~PureCheese() {}

bool PureCheese::is_poisoned() const {
	return false;
}

void PureCheese::cheese_behavior(Mouse* mouse) {
	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
}

// DoorCheese implementation.

DoorCheese::DoorCheese(int row_, int col_) : PureCheese(row_, col_, DOOR_CHEESE) {}

DoorCheese::~DoorCheese() {}

void DoorCheese::cheese_behavior(Mouse* mouse) {

	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
	mouse->set_door_cheese_eaten(true);
	
}

// EscapeCheese implementation.

EscapeCheese::EscapeCheese(int row_, int col_) : PureCheese(row_, col_, ESCAPE_CHEESE) {}

EscapeCheese::~EscapeCheese() {}

void EscapeCheese::cheese_behavior(Mouse* mouse) {
	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
	mouse->set_escape_cheese_eaten((mouse->get_escape_cheese_eaten()) + 1);
}

// HealthCheese implementation.

HealthCheese::HealthCheese(int row_, int col_) : PureCheese(row_, col_, HEALTH_CHEESE) {}

HealthCheese::~HealthCheese() {}

void HealthCheese::cheese_behavior(Mouse* mouse) {
	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
	mouse->increase_health(HEALTH_CHEESE_RESTORE);
	int current_health = mouse->get_health();
	if (current_health > MOUSE_HEALTH) {
		mouse->decrease_health(current_health - MOUSE_HEALTH);
	}
}

// MirrorCheese implementation.

MirrorCheese::MirrorCheese(int row_, int col_) : PureCheese(row_, col_, MIRROR_CHEESE) {}

MirrorCheese::~MirrorCheese() {}

void MirrorCheese::cheese_behavior(Mouse* mouse) {
	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
	// TODO
}

// SpitCheese implementation.

//SpitCheese::SpitCheese(int row_, int col_) : PureCheese(row_, col_, SPIT_CHEESE) {}
//
//SpitCheese::~SpitCheese() {}
//
//void SpitCheese::cheese_behavior(Mouse* mouse) { // FIX
//	//Mouse isn't eating cheese, so don't use set chese eaten function
////	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
//	mouse->spit_cheese(mouse);
//}

// GeneralCheese implementation.

//Does not work
//int GeneralCheese::randInt(int min, int max) {
//	if (max < min)
//		swap(max, min);
//	static random_device rd;
//	static mt19937 generator(rd());
//	uniform_int_distribution<> distro(min, max);
//	return distro(generator);
//}

// LAST 3 CHEESE CONSTRUCTOR PARAMS MUST BE CHANGED TO DESIRED/HARDCODED VALUES
GeneralCheese::GeneralCheese(int row_, int col_) : Cheese(row_, col_, GENERAL_CHEESE, 0, false) {
	// Set poisoned to true with some random probability.
	// 20 percent probability
	
	if (rand() % row_ < 5) {
		poisoned = true;
	}
	else poisoned = false;
}

GeneralCheese::~GeneralCheese() {}

void GeneralCheese::cheese_behavior(Mouse* mouse) {
	mouse->set_cheese_eaten((mouse->get_cheese_eaten()) + 1);
	if (is_poisoned()) {
		mouse->decrease_health(10);
	}
}

bool GeneralCheese::is_poisoned() const {
	return poisoned;
}