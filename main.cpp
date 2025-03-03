#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main() {

	std::cout << "Hello game!" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Title", 100, 100, 1000, 500, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 50;
	rect.h = 50;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

	return 0;
}
