#include "gamescene.h"
#include "barra.h"



void event_handler(SDL_Event event, Barra *player1, Barra *player2, int *running, int *paused){

	while(SDL_PollEvent(&event))
		switch(event.type){
		case SDL_QUIT:
			*running = 1;
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.scancode){
			case SDL_SCANCODE_W:
				player1->controls[0]=1;
				break;
			case SDL_SCANCODE_UP:
				player2->controls[0]=1;
				break;
			case SDL_SCANCODE_S:
				player1->controls[1]=1;
				break;
			case SDL_SCANCODE_DOWN:
				player2->controls[1]=1;
				break;
			case SDL_SCANCODE_ESCAPE:
				*paused *= -1;
				break;
			default:
				break;
			}
			break;
			case SDL_KEYUP:
				switch(event.key.keysym.scancode){
				case SDL_SCANCODE_W:
					player1->controls[0]=0;
					break;
				case SDL_SCANCODE_UP:
					player2->controls[0]=0;
					break;
				case SDL_SCANCODE_S:
					player1->controls[1]=0;
					break;
				case SDL_SCANCODE_DOWN:
					player2->controls[1]=0;
					break;
				default:
					break;
				}
		}

}




void one_player_logic(SDL_Event event, int *running, Bola *ball, Barra *player, Barra *cpu, char *score_str, int *paused){

event_handler(event, player, cpu, running, paused);
	if(*paused == -1){
		//Player Movement Logic
		player_logic(player);
		//Ball Movement Logic
		logic_ball(ball, player, cpu, score_str);
		//CPU Logic
		cpu_logic(cpu, ball);
		//Win Conditions
		if(player->score >= 5 || cpu->score >= 5){
			sprintf(score_str, "%d  %d", player->score, cpu->score);
			player->score = 0;
			cpu->score = 0;
		}
	}


}








