#include <iostream>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>

#include "Shader.h"

std::string file = __FILE__;
int width = 800, height = 600;
float aspectRatio = 800.0f / 600.0f;

float deltaTime = 0.0f;
float lastTime = 0.0f;

int main(int argc, char* argv[])
{
	std::string directory = file.substr(0, file.find_last_of("\\")) + "\\";

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "SDL2 video subsystem couldn't be initialized. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	//Create SDL window
	SDL_Window* window = SDL_CreateWindow("Glad Simple", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!window)
	{
		std::cerr << "SDL2 Window couldn't be created. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	//Create SDL renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cerr << "SDL2 Renderer couldn't be created. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	SDL_GL_SetSwapInterval(0);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cerr << "Failed to create SDL OpenGL Context. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to load GLAD" << std::endl;
		SDL_Quit();
		exit(1);
	}

	SDL_Event event;
	bool running = true;

	//Main Loop
	while (running)
	{
		//Event polling
		SDL_PollEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;
				}
				break;

			default:
				break;
		}

		//Resizing
		SDL_GetWindowSize(window, &width, &height);
		aspectRatio = (float)width / (float)height;

		//Updating
		float currentTime = SDL_GetTicks() / 1000.0f;
		deltaTime = currentTime - lastTime;

		//Drawing
		
		//Buffer swapping
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}