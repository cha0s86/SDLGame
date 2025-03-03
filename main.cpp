#include <iostream>
#include <SDL2/SDL.h>
#include "game.h" 
using namespace std;

Game* game = nullptr;

int main() {

	std::cout << "Hello game!" << std::endl;

	game = new Game();

	game->init("My Game", 100, 100, 1000, 500, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
