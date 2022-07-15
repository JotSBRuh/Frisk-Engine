#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"


int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
		std::cout << "SOMETHING HAS GONE REALLY WRONG. SDL_ERROR: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 720, 480);

	SDL_Texture* grassTexture = window.loadTexture("res\\gfx\\ground_grass_1.png");

    std::vector<Entity> entities = {Entity(v::Vector2f(0, 0), grassTexture)};

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		

		for (Entity& e : entities)
		{ 
			window.render(e);
		}


		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}