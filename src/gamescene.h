#ifndef __GAMESCENE__
#define __GAMESCENE__

#include <SDL2/SDL.h>
#include "bola.h"
#include "barra.h"


void event_handler(SDL_Event event, Barra* player1, Barra* player2, int* running, int* paused);

void one_player_logic(SDL_Event event, int* running, Bola* ball, Barra* player, Barra* cpu, char* score_str, int*paused);

void two_player_logic(SDL_Event event,int* running, Bola* ball, Barra* player1, Barra* player2, char* score_str, int* paused);


#endif
