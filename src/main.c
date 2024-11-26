#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "render.h"
#include "barra.h"
#include "bola.h"
#include "menu.h"




int main(void){

	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	
	init(&window, &renderer, &font);
	//Menu config
	int selected = 0;


	//Game config
	//Player1 config
	//
	Barra player1;
	SDL_Rect player_rect = { 0, WINDOW_HEIGHT / 2, 16, 64};
	player1.rect = player_rect;
	player1.score = 0;
	player1.controls[0] = player1.controls[1] = 0;


	//Player2 config
	//
	Barra player2;
	player_rect.x = WINDOW_WIDTH - 16;
	player2.rect = player_rect;
	player2.score = 0;
	player2.controls[0] = player2.controls[1] = 0;


	//Ball config
	//
	Bola ball;
	ball.vel_x = 5;
	ball.vel_y = 5;
	SDL_Rect ball_rect = {BALL_SPAWN_X, BALL_SPAWN_Y, 16, 16};
	ball.rect = ball_rect;


	//Scoreboard config
	SDL_Color White = {255, 255, 255};
	char score_str[5];
	sprintf(score_str, "%d  %d", player1.score, player2.score);
	SDL_Rect score_rect;



	//Event Handling
	int running = 0;
	int paused = -1;
	SDL_Event event;
	

	//Game loop
	//

	int players = 1;

	while(!running){
		
		if(selected == 0){
		menu_handler(event,&running,&players,&selected);
		draw_menu(renderer,font,players);
		}
		



		redraw(renderer);
	}


}
