#ifndef _L_FUNCTIONS_H
#define _L_FUNCTIONS_H

#include "D:\vs_projs\LConstants\LConstants.h"
#include "D:\vs_projs\LCircle\LCircle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

bool init();
bool checkCollision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b);
bool checkCollision(Circle& a, Circle& b);
bool checkCollision(Circle& a, SDL_Rect& b);
double distanceSquared(int x1, int y1, int x2, int y2);

#endif //_L_FUNCTIONS_H