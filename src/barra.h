#ifndef __BARRA__
#define __BARRA__

#include <SDL2/SDL.h>


typedef struct{
	SDL_Rect rect;
	int score;
	int controls[2];
}Barra;


#include "bola.h"


void cpu_logic(Barra* cpu, Bola* ball);
void player_logic(Barra* player);

#endif
