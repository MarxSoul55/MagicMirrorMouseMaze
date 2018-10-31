// Game.h

#ifndef GAME_H
#define GAME_H
#include "Maze.h"
#include "Actor.h"
#include "globals.h"
#include "UserInterface.h"
#include <string>
#include "Cheese.h"
#include "globals.h"

class Game
{
public:
	Game();//int width, int height);
	~Game();

	//Handles  input and calls all classes and private functions to manage game play.
	void play();

private:
	int current_level;
	Maze *maze;
	Screen  m_screen;

	void refresh_map();
	void refresh_text();
	void refresh_screen();
	void displayPrompt(std::string s);
	void place_actors(Maze * maze);
};

#endif // GAME_H