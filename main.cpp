#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "game.h" 
using namespace std;

Game* game = nullptr;

int main() {

	std::cout << "Hello game!" << std::endl;

	game = new Game();

	game->init("My Game", 100, 100, 1000, 500, false);

	// Open audio stream
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4090) == 0) {
		std::cout << "Audio stream opened!" << std::endl;	
	} else {
		std::cout << "Couldn't open audio stream!" << std::endl;
	}

	// Mix chunk
	Mix_Chunk* track1;

	// Load music to track
	track1 = Mix_LoadWAV("audiotrack1.wav");

	// Play track from channel
	Mix_PlayChannel(-1, track1, 0);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
