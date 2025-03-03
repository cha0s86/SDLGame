#include "game.h"

SDL_Texture* playerTexture;
SDL_Rect srcRect;
SDL_Rect dstRect;

Game::Game() {
		
}

Game::~Game() {

}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems initialized!" << std::endl;
		
		window = SDL_CreateWindow(title, x, y, width, height, flags);

		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	} else {
		isRunning = false;
	}

	SDL_Surface* tempSurface = IMG_Load("player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_FreeSurface(tempSurface);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_w:
					dstRect.y -= 6;
					break;
				case SDLK_a:
					dstRect.x -= 6;
					break;
				case SDLK_s:
					dstRect.y += 6;
					break;
				case SDLK_d:
					dstRect.x += 6;
					break;
			}
		default:
			break;
	}
}

void Game::update() {
	cnt++;
	dstRect.h = 64;
	dstRect.w = 64;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &dstRect);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
