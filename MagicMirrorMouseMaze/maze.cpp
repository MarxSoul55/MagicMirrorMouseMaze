#include "maze.h"
#include "cheese.h"

//Maze::Maze() : nonplayer_mouse_tile(' '), is_escaped(false), cheese(nullptr) {};

Maze::Maze(bool is_test) : nonplayer_mouse_tile(' '), is_escaped(false), cheese(nullptr)
{
	if (is_test == true) test_level();
	else {
		mouse = new Mouse(MOUSE_ROW_DEFAULT, MOUSE_COL_DEFAULT);
		mirror_mouse = new Mouse(MIRROR_MOUSE_ROW_DEFAULT, MIRROR_MOUSE_COL_DEFAULT);
		player_mouse = mouse;
		for (int i = 0; i < MAX_LEVEL; i++) {
			load_level(i);

		}
	};
	set_status(0);
}

Maze::~Maze() {
	delete mouse;
	delete mirror_mouse;
	mouse = nullptr;
	mirror_mouse = nullptr;
	player_mouse = nullptr;
	for (int level = 0; level < MAX_LEVEL; level++) {
		//		for (int row = 0; row < MAZE_HEIGHT; row++)
		//			delete[] map[level][row];
		//		delete[] map[level];
		//		delete[] status[level];
		for (int cheesecount = 0; cheesecount < MAX_CHEESE_PER_LEVEL; cheesecount++) {
			delete cheese_ar_l1[level][cheesecount];
			cheese_ar_l1[level][cheesecount] = nullptr;
		}
		//delete[] cheese_ar_l1[level];
	}
	//	delete[] map;
	//	delete[] status;
	//	delete[] cheese_ar_l1;
}

void Maze::load_level(int level) {

	if (level == 0) {
		string	s[MAZE_HEIGHT] = { "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
			"||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||",
			"||==================DDD===================||===================DDD==================||",
			"||                ||   |                m ||                      ||                ||",
			"||                ||   |          d       ||                      ||                ||",
			"||                ||   |                  ||                      ||                ||",
			"||                ||   |                  ||                      ||                ||",
			"||                ||====    ==============||==============    ====||                ||",
			"||                ||                      ||                      ||                ||",
			"||                ||                      ||                      ||                ||",
			"||                ||                      ||                      ||                ||",
			"||                ||                      ||                      ||                ||",
			"||                ||==============||      ||      ||==============||                ||",
			"||                ||              ||      ||      ||              ||                ||",
			"||                ||              ||      ||      ||              ||                ||",
			"||                ||              ||      ||      ||              ||                ||",
			"||                ||   ||=====    ||      ||      ||    =====||   ||                ||",
			"||                ||   ||         ||      ||      ||         ||   ||                ||",
			"||                ||   ||         ||      ||      ||         ||   ||                ||",
			"||                ||   ||    =======      ||------=======    ||   ||                ||",
			"||                ||   ||          |      ||                 ||   ||                ||",
			"||                || ^ ||          |      ||   m             || ^ ||                ||",
			"||========================================||========================================||",
			"||                                        ||++++++++++++++++++++++++++++++++++++++++||",
			"||==================================================================================||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" };
		char ch[MAZE_WIDTH + 1];
		for (int i = 0; i < MAZE_HEIGHT; i++)
		{
			strcpy_s(ch, s[i].c_str());
			for (int j = 0; j < MAZE_WIDTH; j++)
			{
				map[level][i][j] = ch[j];
			}
		}
		cheese_ar_l1[level][0] = new MirrorCheese(21, 47);
		cheese_ar_l1[level][1] = new MirrorCheese(3, 40);
		cheese_ar_l1[level][2] = new DoorCheese(4, 34);

		status[level][5] = "Disaster! You are a mouse trapped in a";
		status[level][6] = "magical mirror maze. Try eating some magic";
		status[level][7] = "cheese (m) by walking up to it and pressing";
		status[level][8] = "the space bar.";
		status[level][9] = "";
	}
	else if (level == 1) {
		string	s[MAZE_HEIGHT] = { "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
			"||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||",
			"||==================DDD===================||===================DDD==================||",
			"||                 |---|                  ||   |                                    ||",
			"||                                       m||   |                                 m  ||",
			"|| d                  --------------------||   |---|                                ||",
			"||                    |        m          ||   d m |                                ||",
			"||-------||===============================||===============================||       ||",
			"||       ||                               ||                               ||       ||",
			"||       ||                           e   ||                               ||       ||",
			"||   m   ||                               ||                               ||       ||",
			"||       ||                               ||                               ||       ||",
			"||       ||       ||==============||      ||------||==============||       ||       ||",
			"||       ||       ||              ||      ||      ||              ||       ||       ||",
			"||       ||       ||              ||      ||      ||              ||       ||       ||",
			"||       ||       ||              ||      ||      ||              ||       ||       ||",
			"||       ||       ||   ||====||           ||           ||====||   ||       ||       ||",
			"||       ||       ||   ||    ||           ||           ||    ||   ||       ||       ||",
			"||       ||       ||   ||    ||           ||           ||    ||   ||       ||       ||",
			"||                ||   ||    =====    ====||====    =====    ||   ||                ||",
			"||                ||   ||                 ||                 ||   ||                ||",
			"||                || ^ ||                 ||   m             || ^ ||                ||",
			"||==================D D===================||===================D D==================||",
			"||                 |D D|                  ||++++++++++++++++++|D D|+++++++++++++++++||",
			"||==================================================================================||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" };
		char ch[MAZE_WIDTH + 1];
		for (int i = 0; i < MAZE_HEIGHT; i++)
		{
			strcpy_s(ch, s[i].c_str());
			for (int j = 0; j < MAZE_WIDTH; j++)
			{
				map[level][i][j] = ch[j];
			}
		}
		cheese_ar_l1[level][0] = new MirrorCheese(21, 47);
		cheese_ar_l1[level][1] = new EscapeCheese(9, 38);
		cheese_ar_l1[level][2] = new MirrorCheese(10, 5);
		cheese_ar_l1[level][3] = new DoorCheese(5, 3);
		cheese_ar_l1[level][4] = new MirrorCheese(4, 41);
		cheese_ar_l1[level][5] = new MirrorCheese(6, 31);
		cheese_ar_l1[level][6] = new DoorCheese(6, 47);
		cheese_ar_l1[level][7] = new MirrorCheese(6, 49);
		cheese_ar_l1[level][8] = new MirrorCheese(4, 81);

		status[level][5] = "Try eating any cheese (lowercase letter)";
		status[level][6] = "that you find to see what happens! If you";
		status[level][7] = "get stuck, press r to reset.";
		status[level][8] = "";
		status[level][9] = "";

	}
	else if (level == 2) {
		string	s[MAZE_HEIGHT] = { "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
			"||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||",
			"||==================DDD===================||===================DDD==================||",
			"||       ||       ||---|                  ||                      ||       ||       ||",
			"||       ||       ||===================|| ||h||===================||       ||       ||",
			"||       ||                            || ||h||                            ||       ||",
			"||       ||=====================       || ||e||       =====================||       ||",
			"||                                     || ||h||                                     ||",
			"||=======================================-||h=======================================||",
			"||                                        ||                                        ||",
			"||                                   m    ||                                        ||",
			"||                                        ||                                        ||",
			"||==   ===================================||===================================   ==||",
			"||      ||             ||    ||           ||           ||    ||             ||      ||",
			"||      ||=============||    ||           ||           ||    ||=============||      ||",
			"||      h g g g g g          ||           ||           ||        m g g g g g g      ||",
			"||      ||=============||    ||    ||     ||     ||    ||    ||=============||      ||",
			"||                     ||    ||    ||     ||     ||    ||    ||                     ||",
			"||                     ||    ||    ||     ||     ||    ||    ||                     ||",
			"||   d            ||   ||          ||     ||     ||          ||   ||                ||",
			"||                ||   ||          ||     ||     ||          ||   ||                ||",
			"||                || ^ ||          ||     ||     ||          || ^ ||                ||",
			"||==================D D===================||===================D D==================||",
			"||                 |D D|                  ||++++++++++++++++++|D D|+++++++++++++++++||",
			"||==================================================================================||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" };
		char ch[MAZE_WIDTH + 1];
		for (int i = 0; i < MAZE_HEIGHT; i++)
		{
			strcpy_s(ch, s[i].c_str());
			for (int j = 0; j < MAZE_WIDTH; j++)
			{
				map[level][i][j] = ch[j];
			}
		}
		cheese_ar_l1[level][0] = new GeneralCheese(15, 10);
		cheese_ar_l1[level][1] = new GeneralCheese(15, 12);
		cheese_ar_l1[level][2] = new GeneralCheese(15, 14);
		cheese_ar_l1[level][3] = new GeneralCheese(15, 16);
		cheese_ar_l1[level][4] = new GeneralCheese(15, 18);
		cheese_ar_l1[level][5] = new GeneralCheese(15, 67);
		cheese_ar_l1[level][6] = new GeneralCheese(15, 69);
		cheese_ar_l1[level][7] = new GeneralCheese(15, 71);
		cheese_ar_l1[level][8] = new GeneralCheese(15, 73);
		cheese_ar_l1[level][9] = new GeneralCheese(15, 75);
		cheese_ar_l1[level][10] = new GeneralCheese(15, 77);
		cheese_ar_l1[level][11] = new MirrorCheese(15, 65);
		cheese_ar_l1[level][12] = new DoorCheese(19, 5);
		cheese_ar_l1[level][13] = new HealthCheese(15, 8);
		cheese_ar_l1[level][14] = new MirrorCheese(10, 37);
		cheese_ar_l1[level][15] = new HealthCheese(4, 44);
		cheese_ar_l1[level][16] = new HealthCheese(5, 44);
		cheese_ar_l1[level][17] = new HealthCheese(7, 44);
		cheese_ar_l1[level][18] = new HealthCheese(8, 44);
		cheese_ar_l1[level][19] = new EscapeCheese(6, 44);

		status[level][5] = "What's next?";
		status[level][6] = "";
		status[level][7] = "";
		status[level][8] = "";
		status[level][9] = "";
	}
	else if (level == 3) {
		string	s[MAZE_HEIGHT] = { "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
			"||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||",
			"||==================DDD===================||===================DDD==================||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                                        ||                                        ||",
			"||                ||   ||                 ||                 ||   ||                ||",
			"||                || ^ ||                 ||                 || ^ ||                ||",
			"||==================D D===================||===================D D==================||",
			"||                 |D D|                  ||++++++++++++++++++|D D|+++++++++++++++++||",
			"||==================================================================================||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||                                  }}                                              ||",
			"||                                 {{                                               ||",
			"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" };
		char ch[MAZE_WIDTH + 1];
		for (int i = 0; i < MAZE_HEIGHT; i++)
		{
			strcpy_s(ch, s[i].c_str());
			for (int j = 0; j < MAZE_WIDTH; j++)
			{
				map[level][i][j] = ch[j];
			}
		}
		status[level][5] = "To be continued!";
		status[level][6] = "";
		status[level][7] = "";
		status[level][8] = "";
		status[level][9] = "";
	}

	map[level][MOUSE_ROW_DEFAULT][MOUSE_COL_DEFAULT] = '^';
	map[level][MIRROR_MOUSE_ROW_DEFAULT][MIRROR_MOUSE_COL_DEFAULT] = '^';
}

void Maze::test_level() {

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++) {
			map[0][i][j] = ' ';
			map[0][0][j] = '#';
			map[0][19][j] = '#';
		}
		map[0][i][0] = '#';
		map[0][i][29] = '#';
		map[0][i][14] = '#';
		map[0][i][15] = '#';
		map[0][8][13] = 'd';
		map[0][8][16] = 'd';
	}

	mouse = new Mouse(18, 28);
	map[0][18][28] = '^';
	mirror_mouse = new Mouse(18, 1);
	map[0][18][1] = '^';
	player_mouse = mouse;

	map[0][2][1] = 'H';
	cheese_ar_l1[0][0] = new HealthCheese(2, 1);
	map[0][5][1] = 'D';
	cheese_ar_l1[0][1] = new DoorCheese(5, 1);
	map[0][7][1] = 'E';
	cheese_ar_l1[0][2] = new EscapeCheese(7, 1);
	map[0][9][5] = 'M';
	cheese_ar_l1[0][3] = new MirrorCheese(9, 5);
	map[0][9][15] = 'M';
	cheese_ar_l1[0][3] = new MirrorCheese(9, 15);
	//	map[0][11][1] = 'S';
	//	cheese_ar_l1[0][4] = new SpitCheese(11, 1);
	map[0][13][1] = 'G';
	cheese_ar_l1[0][5] = new GeneralCheese(13, 1);

	map[0][13][5] = '*';
	//	bug_ar[0][5] = new Bug(13, 1);


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++) {
			map[1][i][j] = ' ';
			map[1][0][j] = '#';
			map[1][19][j] = '#';
		}
		map[1][i][0] = '#';
		map[1][i][29] = '#';
		map[1][i][14] = '#';
		map[1][i][15] = '#';
		map[1][6][13] = 'd';
		map[1][6][16] = 'd';
	}

};

void Maze::set_char(int level, int row, int col, char someChar)
{
	map[level][row][col] = someChar;
}

char Maze::get_char(int level, int row, int col)
{
	return map[level][row][col];
}

void Maze::move_mice(int level, Direction dir)
{
	//Set direction used for non-player mouse
	Direction mirrorDir;
	bool is_nonplayer_mouse = true;
	bool is_player_mouse = false;

	if (dir == LEFT)		mirrorDir = RIGHT;
	else if (dir == RIGHT)	mirrorDir = LEFT;
	else					mirrorDir = dir;

	//Clear the map where the mouse is
	if (player_mouse == mouse) {
		map[level][mouse->get_row()][mouse->get_column()] = ' ';
		map[level][mirror_mouse->get_row()][mirror_mouse->get_column()] = nonplayer_mouse_tile;
	}
	else {
		map[level][mouse->get_row()][mouse->get_column()] = nonplayer_mouse_tile;
		map[level][mirror_mouse->get_row()][mirror_mouse->get_column()] = ' ';
	}

	//Attempts to turn if not facing the given direction, or move if already facing.
	//If successful, nonplayer mouse does the same.
	char ignore = ' ';

	if (player_mouse == mouse) {
		if (player_mouse->move(level, dir, is_player_mouse, ignore)) {
			mirror_mouse->move(level, mirrorDir, is_nonplayer_mouse, nonplayer_mouse_tile);
			status[level][9] = "";
		}
		//If player mouse couldn't move or turn, do nothing.
		else status[level][9] = "It hurts to run into things.";
	}
	else {
		if (player_mouse->move(level, mirrorDir, is_player_mouse, ignore)) {
			mouse->move(level, dir, is_nonplayer_mouse, nonplayer_mouse_tile);
			status[level][9] = "";
		}
		//If player mouse couldn't move or turn, do nothing.
		else status[level][9] = "It hurts to run into things.";
	}


	//Update the map with where the mouse is, whether it got moved or not
	map[level][mouse->get_row()][mouse->get_column()] = mouse->get_icon();
	map[level][mirror_mouse->get_row()][mirror_mouse->get_column()] = mirror_mouse->get_icon();

	return;
}

Cheese * Maze::get_cheese_at(int level, int row, int col) const
{
	for (int i = 0; i < MAX_CHEESE_PER_LEVEL; i++) {
		if (cheese_ar_l1[level][i]->get_row() == row && cheese_ar_l1[level][i]->get_col() == col)
			return cheese_ar_l1[level][i];
	}
	return nullptr;
}

string Maze::get_status(int level, int line) {
	return status[level][line];
}

void Maze::place_actors() {
	mouse->set_maze(this);
	mirror_mouse->set_maze(this);
}

void Maze::flip_to_mirror()
{
	if (player_mouse == mouse) player_mouse = mirror_mouse;
	else player_mouse = mouse;
}

void Maze::try_actions(int &level) {
	int row = player_mouse->get_facing_r();
	int col = player_mouse->get_facing_c();

	//if there is nothing there, spit!
	if (map[level][row][col] == ' ')
		status[level][9] = "There is nothing to eat there."; //player_mouse->spit_cheese(mouse); PENDING IMPLEMENTATION
															 //if it is a door, try to eat through
	else if (map[level][row][col] == 'D') eat_door(level);
	else if (map[level][row][col] == GENERAL_CHEESE ||
		map[level][row][col] == DOOR_CHEESE ||
		map[level][row][col] == ESCAPE_CHEESE ||
		map[level][row][col] == HEALTH_CHEESE ||
		map[level][row][col] == SPIT_CHEESE ||
		map[level][row][col] == MIRROR_CHEESE
		) eat_cheese(level, row, col);
	else status[level][9] = "There is nothing to eat there.";

	set_status(level);
}

void Maze::eat_cheese(int level, int row, int col) {
	if (map[level][row][col] == MIRROR_CHEESE) {
		//Tutorial text
		if (level == 0 && row == 21) {
			status[level][5] = "Hmmmm. Something odd just happened...Perhaps";
			status[level][6] = "there are other strange cheeses lying around";
			status[level][7] = "that you can eat?";
			status[level][8] = "";
		}

		flip_to_mirror();
		map[level][row][col] = ' ';
		mouse->set_cheese_eaten(mouse->get_cheese_eaten() + 1);
		if (level == 0) {
			if (player_mouse == mouse) {
				string t = "||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||";
				string b = "||                                        ||++++++++++++++++++++++++++++++++++++++++||";
				for (int j = 0; j < 86; j++)
				{
					map[level][1][j] = t[j];
					map[level][23][j] = b[j];
				}
			}
			else {
				string t = "||+++++++++++++++++|DDD|++++++++++++++++++||                  |DDD|                 ||";
				string b = "||++++++++++++++++++++++++++++++++++++++++||                                        ||";
				for (int j = 0; j < 86; j++)
				{
					map[level][1][j] = t[j];
					map[level][23][j] = b[j];
				}
			}
		}
		else if (player_mouse == mouse) {
			string t = "||                 |DDD|                  ||++++++++++++++++++|DDD|+++++++++++++++++||";
			string b = "||                 |D D|                  ||++++++++++++++++++|D D|+++++++++++++++++||";
			for (int j = 0; j < 86; j++)
			{
				map[level][1][j] = t[j];
				map[level][23][j] = b[j];
			}
		}
		else {
			string t = "||+++++++++++++++++|DDD|++++++++++++++++++||                  |DDD|                 ||";
			string b = "||+++++++++++++++++|D D|++++++++++++++++++||                  |D D|                 ||";
			for (int j = 0; j < 86; j++)
			{
				map[level][1][j] = t[j];
				map[level][23][j] = b[j];
			}
		}
	}
	else if (map[level][row][col] == ESCAPE_CHEESE) {
		//Tutorial text
		if (level == 1 && row == 9) {
			status[level][5] = "This cheese is so exciting (e) it feels like";
			status[level][6] = "if you eat enough of them, you could escape";
			status[level][7] = "this whole maze!";
			status[level][8] = "";
		}

		cheese = get_cheese_at(level, row, col);
		cheese->cheese_behavior(mouse);		// always update info about mouse, not mirror mouse
		map[level][row][col] = ' ';
		if (mouse->get_escape_cheese_eaten() == ESCAPE_CHEESE_NEEDED) {
			is_escaped = true;
			status[level][5] = "You have eaten enough cheese to escape!";
			status[level][6] = "Press return to quit.";
			status[level][7] = "";
			status[level][8] = "";
		}
	}
	else if (map[level][row][col] == DOOR_CHEESE) {
		//Tutorial text
		if (level == 0 && row == 4) {
			status[level][5] = "This destructive (d) cheese makes you feel";
			status[level][6] = "stronger, like you could eat through that";
			status[level][7] = "exit door (D) over there. Try walking up to";
			status[level][8] = "it and pressing the space bar.";
		}

		if (mouse->get_door_cheese_eaten() == false) {
			cheese = get_cheese_at(level, row, col);
			cheese->cheese_behavior(mouse);		// always update info about mouse, not mirror mouse
			map[level][row][col] = ' ';
		}
		//Tutorial text
		else if (level == 1) {
			status[level][5] = "This (d) cheese is pretty powerful stuff.";
			status[level][6] = "You can only handle one at a time. Chew";
			status[level][7] = "through another door first, or reset (press";
			status[level][8] = "r) if you are stuck.";
		}
		else status[level][9] = "Eat through a door first!";
	}
	else {
		//Tutorial text
		if (level == 2 && col == 77) {
			status[level][5] = "Ew, generic (g) cheese. Watch out, sometimes";
			status[level][6] = "it is poisoned.";
			status[level][7] = "";
			status[level][8] = "";
		}
		else if (level == 2 && col == 8) {
			status[level][5] = "Wow, that's some healthy (h) cheese! You";
			status[level][6] = "instantly feel a bit better.";
			status[level][7] = "";
			status[level][8] = "";
		}
		cheese = get_cheese_at(level, row, col);
		cheese->cheese_behavior(mouse);		// always update info about mouse, not mirror mouse
		map[level][row][col] = ' ';
	}

}

void Maze::eat_door(int &level) {
	if (mouse->get_door_cheese_eaten()) {
		level++;
		load_level(level);
		mouse->set_position(MOUSE_ROW_DEFAULT, MOUSE_COL_DEFAULT);
		mirror_mouse->set_position(MIRROR_MOUSE_ROW_DEFAULT, MIRROR_MOUSE_COL_DEFAULT);
		player_mouse = mouse;
		mouse->set_door_cheese_eaten(false);
		nonplayer_mouse_tile = ' ';
	}
}
//void Maze::spit(int level, int r, int c) {
//	for (int i = 0; i < 20; i++) {
//		if (sp_ar[level][i] == nullptr) {
//			sp_ar[level][i] = new SpitCheese(r, c);
//			set_char(level, r, c, '@');
//			return;
//		}
//	}
//}

//bool Maze::escaped() {
//	return is_escaped;
//}

Cheese * Maze::searchCheese(int level, int row, int col) const
{
	int cheeseRow, cheeseColumn, closest = 50, row_diff, col_diff, distance, i;

	int temp = abs(-3);

	for (i = 0; i < 6; i++)
	{
		cheeseRow = cheese_ar_l1[level][i]->get_row();
		cheeseColumn = cheese_ar_l1[level][i]->get_col();

		row_diff = abs(cheeseRow - row);
		col_diff = abs(cheeseColumn - col);
		distance = row_diff + col_diff;

		if (distance < closest)
			closest = distance;
	}

	for (i = 0; i < 6; i++)
	{
		cheeseRow = cheese_ar_l1[level][i]->get_row();
		cheeseColumn = cheese_ar_l1[level][i]->get_col();

		row_diff = abs(cheeseRow - row);
		col_diff = abs(cheeseColumn - col);
		distance = row_diff + col_diff;

		if (distance == closest)
			break;
	}

	return cheese_ar_l1[level][i];
}

void Maze::reset(int level) {
	load_level(level);
	mouse->set_position(MOUSE_ROW_DEFAULT, MOUSE_COL_DEFAULT);
	mirror_mouse->set_position(MIRROR_MOUSE_ROW_DEFAULT, MIRROR_MOUSE_COL_DEFAULT);
	player_mouse = mouse;
	mouse->set_door_cheese_eaten(false);
	nonplayer_mouse_tile = ' ';
}

void Maze::set_status(int level) {
	status[level][0] = "Health:                " + to_string(mouse->get_health());
	status[level][1] = "Cheese points:         " + to_string(mouse->get_cheese_eaten());
	string doors_edible = "no";
	if (mouse->get_door_cheese_eaten()) doors_edible = "yes";
	status[level][2] = "Doors edible:          " + doors_edible;
	status[level][3] = "Escape cheese:         " + to_string(mouse->get_escape_cheese_eaten()) + " / 10";
	status[level][4] = "ROOM " + to_string(level + 1);

}