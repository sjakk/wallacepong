#ifndef __BOLA__
#define __BOLA__

#include <SDL2/SDL.h>
#include "helpers.h"


typedef struct{
	SDL_Rect rect;
	int vel_x;
	int vel_y;
}Bola;


#include "barra.h"

void logic_ball(Bola* ball,Barra* player, Barra* cpu, char* score_str);


#endif
