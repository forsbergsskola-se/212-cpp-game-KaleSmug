//Using SDL and standard IO
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Image.h"
#include "Window.h"
#include <SDL_image.h>
#include "SDL_ImageImageLoader.h"
#include "Font.h"
#include "Sushi.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

bool checkCollision(SDL_Rect a, SDL_Rect b);


//The window we'll be rendering to
SDL_Window* gWindow{};

//The surface contained by the window
SDL_Surface* gScreenSurface{};

//The font for displaying score
//Font* font{};

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{};
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("img/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "img/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

class SushiLabel : ISushiObserver {
	// TODO: constructor (Sushi*) sushi->addObserver(this);
	Sushi* mySushi;


public:
	SushiLabel(Sushi* sushi) : mySushi{ sushi } {
		mySushi->addObserver(this);
	};
	TextRenderer scoreText;
	void onSushiChange(int newSushi) override {
		scoreText.gFont = TTF_OpenFont("Fonts/samuraiBlast.ttf", 28);
		std::string scoreString = "Score-" + std::to_string(newSushi);
		scoreText.loadFromRenderedText(scoreString, SDL_Color{ 255, 255, 20 });
		scoreText.rect.x = (SCREEN_WIDTH - scoreText.rect.w) / 2;
		scoreText.rect.y = 0;
	}

};
int main(int argc, char* args[])
{
	IImageLoader* imageLoader = new SDL_ImageImageLoader{};
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT, imageLoader };
	std::unique_ptr<Image> image = window.LoadImage("Images/sushi.png");
	Sushi sushi{ image.get(), &window};
	
	SDL_Rect mouseCol{ 0,0,1,1 };
	SushiLabel sushiLabel{ &sushi };

	if (TTF_Init() == -1)
	{
		printf("Failed to initialize!\n");
		return -1;
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{

		SDL_Event e; bool quit = false;
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				//Checks to see if the sushi has been clicked, and then adds to score if it has
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&mouseCol.x, &mouseCol.y);
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (checkCollision(mouseCol, sushi.GetSushiHitbox()))
					{
						sushi.increase();
					}
					break;
				}

			}
			window.clear();

			

			window.Render(image.get());
			window.Render(sushiLabel.scoreText);
			window.present();
		}

	}

	return 0;
}



bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}