#include "game.h"
#include "maze.h"
#include "globals.h"
#include "UserInterface.h"
#include <string>

using namespace std;


Game::Game()//, int height)
	: m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), current_level(0)
{
	bool isTest = false;
	maze = new Maze(isTest);
	place_actors(maze);
}

Game::~Game() {
	delete maze;
	maze = nullptr;
}

void Game::play() {

	//Create new maze
	//refresh_screen();
	//m_screen.gotoXY(39, 25);
	displayPrompt("Press the Enter key to begin MAGIC MIRROR MOUSE MAZE ");
	char choice = '\0';
	bool win = false;
	waitForEnter();

	////To test specific level, use the next line.
	//current_level = 2;

	refresh_screen();
	while (choice != 'q' && win != true) {
		if (getCharIfAny(choice)) {
			switch (choice) {
			case ARROW_LEFT:
				maze->move_mice(current_level, LEFT);
				refresh_screen();
				//				m_screen.printChar('L');
				break;
			case ARROW_RIGHT:
				maze->move_mice(current_level, RIGHT);
				refresh_screen();
				//				m_screen.printChar('R');
				break;
			case ARROW_UP:
				maze->move_mice(current_level, UP);
				refresh_screen();
				//				m_screen.printChar('U');
				break;
			case ARROW_DOWN:
				maze->move_mice(current_level, DOWN);
				refresh_screen();
				//				m_screen.printChar('D');
				break;
			case ' ':
				maze->try_actions(current_level);
				//if (maze->escaped() == true) {
				//	refresh_screen();
				//	waitForEnter();
				//	return;
				//}
				//if(maze->is_edible(current_level))
				refresh_screen();
				break;
			case 'r':
				maze->reset(current_level);
				refresh_screen();
				break;
			case 'q':
				return;
			default:
				break;
			}
		}
		choice = ' ';
		//		refresh_screen();
	}

	//While loop for while game hasn't ended
	//Get input from player until quit, die, or win
	//If arrows, have maze move the mouse
	//If facing a cheese and press eat button, have current mouse eat the cheese at
	//location(row,col) given by maze as mouse location and direction
	//If facing door and press eat button, either print "you haven't eaten the necessary cheese"
	//or enter next level: increment current level to next level, show maze next level array,
	//resets mouse positions to default 
}

void Game::displayPrompt(std::string s)
{
	m_screen.gotoXY(PROMPT_X, PROMPT_Y);
	m_screen.printStringClearLine(s);   // overwrites previous text
	m_screen.refresh();
}

void Game::refresh_screen() {
	m_screen.clear();
	refresh_map();
	refresh_text();
	m_screen.gotoXY(0, 30);
}

void Game::refresh_map() {
	for (int r = 0; r < MAZE_HEIGHT; r++) {
		for (int c = 0; c < MAZE_WIDTH; c++) {
			m_screen.printChar(maze->get_char(current_level, r, c));
		}
		m_screen.printChar('\n');
	}
}

void Game::refresh_text() {

	for (int i = 0; i < 5; i++) {
		m_screen.gotoXY(3, 25 + i);
		m_screen.printString(maze->get_status(current_level, i));
	}
	for (int i = 5; i < 10; i++) {
		m_screen.gotoXY(39, 20 + i);
		m_screen.printString(maze->get_status(current_level, i));
	}
}

void Game::place_actors(Maze * maze) {
	maze->place_actors();
}