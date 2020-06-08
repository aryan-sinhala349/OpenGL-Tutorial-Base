#include <iostream>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL/SDL.h>

#include "Shader.h"

#ifdef main
#undef main
#endif

enum class VSyncMode
{
	Adaptive = -1,
	Immediate = 0,
	Synchronized = 1
};

std::string file = __FILE__;
int width = 800, height = 600;
float aspectRatio = 800.0f / 600.0f;

float deltaTime = 0.0f;
float lastTime = 0.0f;

VSyncMode vsync = VSyncMode::Immediate;

float vertices[12] =
{
	-0.5f, -0.5f, 0.0f, //0
	 0.5f, -0.5f, 0.0f, //1
	 0.5f,  0.5f, 0.0f, //2
	-0.5f,  0.5f, 0.0f  //3
};

uint32_t indices[6] =
{
	0, 1, 2,
	2, 3, 0
};

uint32_t vao = 0, vbo = 0, ebo = 0;

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

	SDL_GLContext context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cerr << "Failed to create SDL OpenGL Context. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	
	if (SDL_GL_SetSwapInterval((int)vsync))
		std::cerr << "Failed to set swap interval. Error: " << SDL_GetError() << std::endl;

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to load GLAD" << std::endl;
		SDL_Quit();
		exit(1);
	}

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glCreateBuffers(1, &vbo);
	glCreateBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

		glViewport(0, 0, width, height);

		//Updating
		float currentTime = SDL_GetTicks() / 1000.0f;
		deltaTime = currentTime - lastTime;

		//printf("FPS: %i\n", (int)round(1.0f / deltaTime));

		lastTime = currentTime;

		//Drawing
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		//Buffer swapping
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}