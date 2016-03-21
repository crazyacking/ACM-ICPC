#include "D:\vs_projs\LFunctions\LFunctions\LFunctions.h"
#include "D:\vs_projs\LGlobals\LGlobals.h"
#include "D:\vs_projs\LWindow\LWindow\LWindow.h"
#include <iostream>

bool init()
{
	// Initialize SDL video
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK) < 0)
	{
		std::cout << "Could not initialize SDL! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}
		if (SDL_NumJoysticks() < 1)
		{
			std::cout << "Warning: No joysticks connected!" << std::endl;
		}
		else
		{
			int numOfSticks = SDL_NumJoysticks();
			int controllerIndex = 0;
			std::cout << "Num of joysticks: " << numOfSticks << std::endl;
			SDL_Joystick* joystick = NULL;
			for (int joystickIndex = 0; joystickIndex < numOfSticks; ++joystickIndex)
			{
				if (!SDL_IsGameController(joystickIndex))
				{
					continue;
				}
				if (controllerIndex >= numOfSticks)
				{
					std::cout << "Warning: Controller index is larger than number of sticks. This implies that none of the joysticks were a controller!" << std::endl;
					break;
				}
				gGameControllers[controllerIndex] = SDL_GameControllerOpen(joystickIndex);
				if (gGameControllers[controllerIndex] == NULL)
				{
					std::cout << "Warning: Unable to open game controller " << controllerIndex << "! SDL Error: " << SDL_GetError() << std::endl;
				}
				else
				{
					joystick = SDL_GameControllerGetJoystick(gGameControllers[controllerIndex]);
					gControllerHaptics[controllerIndex] = SDL_HapticOpenFromJoystick(joystick);
					if (gControllerHaptics[controllerIndex] == NULL)
					{
						std::cout << "Warning: Controller does not support haptics! SDL Error: " << SDL_GetError() << std::endl;
					}
					else
					{
						if (SDL_HapticRumbleInit(gControllerHaptics[controllerIndex]) < 0)
						{
							std::cout << "Warning: Unable to initialize rumble! SDL Error: " << SDL_GetError() << std::endl;
						}
					}
				}
				std::cout << "Game Controller Name: " << SDL_GameControllerName(gGameControllers[controllerIndex]) << std::endl;
				++controllerIndex;
			}
			joystick = NULL;
		}
		// These commented gWindow lines should be used when LWindow class isn't in use.
		//gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		//	SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//if (gWindow == NULL)
		if (gWindow.init())
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			// Read above if (gWindow.init())... for explanation why this is commented out
			//gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			gRenderer = gWindow.getRenderer();
			if (gRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				// Initialize SDL_image
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}
				// Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool checkCollision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	for (int Abox = 0; Abox < a.size(); Abox++)
	{
		leftA = a[Abox].x;
		rightA = a[Abox].x + a[Abox].w;
		topA = a[Abox].y;
		bottomA = a[Abox].y + a[Abox].h;
		//Go through the B boxes
		for (int Bbox = 0; Bbox < b.size(); Bbox++)
		{
			//Calculate the sides of rect B
			leftB = b[Bbox].x;
			rightB = b[Bbox].x + b[Bbox].w;
			topB = b[Bbox].y;
			bottomB = b[Bbox].y + b[Bbox].h;
			//If no sides from A are outside of B
			if (((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB)) == false)
			{
				//A collision is detected
				return true;
			}
		}
	} //If neither set of collision boxes touched
	return false;
}

bool checkCollision(Circle& a, Circle& b)
{
	// Calculate total radius squared
	int totalRadiusSquared = a.r + b.r;
	totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

	// If the distance between the centers of the circles is less than the sum of their radii
	if (distanceSquared(a.x, a.y, b.x, b.y) < (totalRadiusSquared))
	{
		// The circles have collided
		return true;
	}
	// If not
	return false;
}

bool checkCollision(Circle& a, SDL_Rect& b)
{
	// Closest point on collision box
	int cX, cY;

	// Find closest x offset
	if (a.x < b.x)
	{
		cX = b.x;
	}
	else if (a.x > b.x + b.w)
	{
		cX = b.x + b.w;
	}
	else
	{
		cX = a.x;
	}
	// Find closest y offset
	if (a.y < b.y)
	{
		cY = b.y;
	}
	else if (a.y > b.y + b.h)
	{
		cY = b.y + b.h;
	}
	else
	{
		cY = a.y;
	}
	// If the closest point is inside the circle
	if (distanceSquared(a.x, a.y, cX, cY) < a.r * a.r)
	{
		// This box and the circle have collided
		return true;
	}
	// If the shapes have not collided
	return false;
}

double distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}